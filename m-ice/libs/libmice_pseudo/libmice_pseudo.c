#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <err.h>

#include <mice_pseudo.h>

MCRYPT   crypto_module;
char    *pseudo_key;
char    *key;
size_t  longest_key;
int     IV_len;
char    IV[16];
char    enc_table[256];
char    dec_table[256];

int     psd_debug = 0;


unsigned char *base64_encode(unsigned char *input, int len);
unsigned char *base64_decode(unsigned char *buf, unsigned int *len);

/*
** pseudonymisation init function
** takes no argument to initialize
** pseudo. scheme
*/
int psd_init(void)
{
  register int  i;


  /* check if key exists*/
  if(pseudo_key == NULL)
  {
    warnx("libmice_pseudo: pseudo_key invalid\n");
    return(-1);
  }


  if((crypto_module = mcrypt_module_open("twofish", NULL, "cfb", NULL)) == MCRYPT_FAILED)
  {
    warnx("libmice_pseudo: cannot open mcrypt module\n");
    return(-2);
  }

  if( (IV_len = mcrypt_enc_get_iv_size(crypto_module)) <= 0 )
  {
    warnx("libmice_pseudo: cannot get IV size\n");
    return(-3);
  }
  
  if(IV_len != sizeof(IV))
  {
    warnx("libmice_pseudo: IV size does not match\n");
    return(-4);
  }

  /* when we use the IV we have to propagate it XXX
  srand(time(0));
  for(i = 0; i < IV_len; i++)
    IV[i] = rand();
  */
  memset(IV, 1, IV_len);

  if( (key = (char *) calloc(1, 16)) == NULL)  // 128 bit
  {
    warnx("libmice_pseudo: calloc failed\n");
    return(-5);
  }
  memmove(key, pseudo_key, longest_key);
  if(mcrypt_generic_init(crypto_module, key, 16, IV) < 0)
  {
    warnx("libmice_pseudo: cannot init. mcrypt framework\n");
    return(-6);
  }

  if(mcrypt_enc_self_test(crypto_module))
  {
    warnx("libmice_pseudo: error during mcrypt selftest\n");
    return(-7);
  }
    
  return(0);
}


/*
** pseudonymisation set key function
** just make the key available for the library
** in the case we got a combined key generated
** by someone else.
** this function accepts an ASCII encoded key
** only!
** return value have to be freed by caller!
*/
char *psd_set_key(char *key, size_t *key_len)
{
  if(key == NULL)
    return(NULL);

  pseudo_key = psd_ascii_decode(key, key_len);
    
  return(pseudo_key);
}

/*
** pseudonymisation key generate function
** accepts <num_keys> shared keys to generate
** the key (return value) used for pseudo. on
** the client.
** return value have to be freed by caller!
*/
char *psd_generate_key(size_t num_keys, char **keys, size_t *key_len)
{
  size_t  i, j;


  /* combine keys using XOR */
  for(i = 0, longest_key = 0; i < num_keys && keys[i] != NULL; i++)
    longest_key = (longest_key > strlen(keys[i])) ? longest_key : strlen(keys[i]);

  if(psd_debug)
    warnx("libmice_pseudo: longest key = %d\n", longest_key);
    
  if(i != num_keys && keys[i] == NULL)
    return(NULL); // num_keys is bigger then elements in array keys

  if(longest_key == 0)
    return(NULL); // no keys at all

  if( (pseudo_key = (char *) calloc(longest_key, sizeof(char))) == NULL)
    return(NULL);

  for(i = 0; i < num_keys; i++)
    for(j = 0; keys[i][j] != '\0' && j < longest_key; j++)
      pseudo_key[j] = (char) ( (pseudo_key[j] & 0xFF) ^ (keys[i][j] & 0xFF) );
  *key_len = longest_key;
  
  if(psd_debug)
    warnx("libmice_pseudo: pseudo_key[%u] = %s\n", *key_len, pseudo_key);
    
  return(pseudo_key);
}


/*
** pseudonymisation deidentification function
** takes the combined pseudo. key to deidentify
** the <identifier>. the pseudonym is returned.
*/
char *psd_deidentify(char *identifier)
{
  char            *enc_psd, *pseudonym;
  size_t          id_len = strlen(identifier), enc_psd_len;
  register int    i;


  if(id_len == 0)
  {
    warnx("libmice_pseudo: id_len invalid\n");
    return(NULL);
  }

  if(psd_debug)
    warnx("libmice_pseudo: psd_debug: id_len = %d\n", id_len);
    
  if( (pseudonym = (char *) calloc(id_len, sizeof(char))) == NULL)
  {
    warnx("libmice_pseudo: calloc failed\n");
    return(NULL);
  }

  memcpy(pseudonym, identifier, id_len);
  
  for(i = 0; i < id_len; i++)
    mcrypt_generic(crypto_module, &pseudonym[i], sizeof(char));

  if(psd_debug)
    warnx("libmice_pseudo: psd_debug: encrypted id with %d iterations\n", i);


  enc_psd = psd_ascii_encode(pseudonym, id_len); // error gots propagated

  free(pseudonym);
  return(enc_psd);
}


/*
** pseudonymisation reidentification function
** takes the combined pseudo. key to reidentify
** the <pseudonym>. the identifier is returned
** and must be freed by the caller.
*/
char *psd_reidentify(char *pseudonym)
{
  char            *dec_psd, *identifier;
  size_t          psd_len = strlen(pseudonym), dec_psd_len;
  register int    i;


  if(psd_len == 0)
  {
    warnx("libmice_pseudo: psd_len invalid\n");
    return(NULL);
  }

  if( (dec_psd = psd_ascii_decode(pseudonym, &dec_psd_len)) == NULL)
  {
    warnx("libmice_pseudo: ascii decoding failed\n");
    return(NULL);
  }

  if( (identifier = (char *) calloc(dec_psd_len, sizeof(char))) == NULL)
  {
    warnx("libmice_pseudo: calloc failed\n");
    free(dec_psd);
    return(NULL);
  }

  memcpy(identifier, dec_psd, dec_psd_len);
  free(dec_psd);

  for(i = 0; i < dec_psd_len; i++)
    mdecrypt_generic(crypto_module, &identifier[i], sizeof(char));

  return(identifier);
}


/*
** pseudonymisation deidentification function
** for numbers.
** takes the combined pseudo. key to deidentify
** the <identifier>. the pseudonym is returned.
*/
long psd_deidentify_num(long identifier, char *key, size_t key_len)
{
  char            *pseudonym_ptr,
                  *identifier_ptr;
  long            pseudonym;  
  size_t          id_len = sizeof(identifier);
  register int    i;

  
  if(psd_debug)
    warnx("libmice_pseudo: psd_debug: id_len = %d\n", id_len);

  /* XXX this is just a (insecure) workaround until I have a better idea */
  pseudonym_ptr   = (char *) &pseudonym;
  identifier_ptr  = (char *) &identifier;
  for(i = 0; i < id_len; i++)
    pseudonym_ptr[i] = identifier_ptr[i] ^ key[i];
  
  return(pseudonym);
}


/*
** pseudonymisation reidentification function
** for numbers.
** takes the combined pseudo. key to reidentify
** the <pseudonym>. the identifier is returned
** and must be freed by the caller.
*/
long psd_reidentify_num(long pseudonym, char *key, size_t key_len)
{
  char            *pseudonym_ptr,
                  *identifier_ptr;
  long            identifier;
  size_t          psd_len = sizeof(pseudonym);
  register int    i;


  if(psd_debug)
    warnx("libmice_pseudo: psd_debug: psd_len = %d\n", psd_len);

  /* XXX this is just a (insecure) workaround until I have a better idea */
  pseudonym_ptr   = (char *) &pseudonym;
  identifier_ptr  = (char *) &identifier;
  for(i = 0; i < psd_len; i++)
    identifier_ptr[i] = pseudonym_ptr[i] ^ key[i];

  return(identifier);
}


/*
** pseudonymisation deinit function
** takes no argument and frees the pseuso_key
** as well as closes the mcrypt framework.
*/
int psd_deinit(void)
{
  if(pseudo_key != NULL)
  {
    memset(pseudo_key, longest_key, 0);
    free(pseudo_key);
  }
  if(key != NULL)
  {
    memset(key, longest_key, 0);
    free(key);
  }

  if(IV != NULL)
    memset(IV, sizeof(IV), 0);

  mcrypt_generic_deinit(crypto_module);
  mcrypt_module_close(crypto_module);

  return(0);
}


/* convert binary to ascii */
char *psd_ascii_encode(char *bin_string, size_t bin_len)
{
  return(base64_encode(bin_string, bin_len));   
}

/* convert binary from ascii */
char *psd_ascii_decode(char *char_string, size_t *bin_len)
{
  return(base64_decode(char_string, bin_len));
}



/* EOF */

