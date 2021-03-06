/*
 * radius.h	Constants of the radius protocol.
 *
 * Version:	$Id: radius.h,v 1.2 2005/08/03 10:58:29 thomas Exp $
 *
 */


#define PW_TYPE_STRING			0
#define PW_TYPE_INTEGER			1
#define PW_TYPE_IPADDR			2
#define PW_TYPE_DATE			3
#define PW_TYPE_ABINARY			4
#define PW_TYPE_OCTETS			5
#define PW_TYPE_IFID			6
#define PW_TYPE_IPV6ADDR		7
#define PW_TYPE_IPV6PREFIX		8

#define	PW_AUTHENTICATION_REQUEST	1
#define	PW_AUTHENTICATION_ACK		2
#define	PW_AUTHENTICATION_REJECT	3
#define	PW_ACCOUNTING_REQUEST		4
#define	PW_ACCOUNTING_RESPONSE		5
#define	PW_ACCOUNTING_STATUS		6
#define PW_PASSWORD_REQUEST		7
#define PW_PASSWORD_ACK			8
#define PW_PASSWORD_REJECT		9
#define	PW_ACCOUNTING_MESSAGE		10
#define PW_ACCESS_CHALLENGE		11
#define PW_STATUS_SERVER		12
#define PW_STATUS_CLIENT		13
#define PW_DISCONNECT_REQUEST		40
#define PW_DISCONNECT_ACK		41
#define PW_DISCONNECT_NAK		42
#define PW_COF_REQUEST			43
#define PW_COF_ACK			44
#define PW_COF_NAK			45

#define PW_AUTH_UDP_PORT                1812
#define PW_ACCT_UDP_PORT                1813
#define PW_POD_UDP_PORT			1700

#define	PW_USER_NAME			1
#define	PW_USER_PASSWORD		2
#define	PW_PASSWORD			2
#define	PW_CHAP_PASSWORD		3
#define	PW_NAS_IP_ADDRESS		4
#define	PW_NAS_PORT			5
#define	PW_SERVICE_TYPE			6
#define	PW_FRAMED_PROTOCOL		7
#define	PW_FRAMED_IP_ADDRESS		8
#define	PW_FRAMED_IP_NETMASK		9
#define	PW_FRAMED_ROUTING		10
#define	PW_FILTER_ID			11
#define	PW_FRAMED_MTU			12
#define	PW_FRAMED_COMPRESSION		13
#define	PW_LOGIN_IP_HOST		14
#define	PW_LOGIN_SERVICE		15
#define	PW_LOGIN_TCP_PORT		16
#define PW_OLD_PASSWORD			17
#define PW_REPLY_MESSAGE		18
#define PW_CALLBACK_NUMBER		19
#define PW_CALLBACK_ID			20
#if 0
/*
 *  Deprecated, and no longer used.
 */
#define PW_EXPIRATION			21
#endif
#define PW_FRAMED_ROUTE			22
#define PW_FRAMED_IPXNET		23
#define PW_STATE			24
#define PW_CLASS			25
#define PW_VENDOR_SPECIFIC		26
#define PW_SESSION_TIMEOUT		27
#define PW_IDLE_TIMEOUT			28
#define PW_CALLED_STATION_ID		30
#define PW_CALLING_STATION_ID		31
#define PW_NAS_IDENTIFIER		32
#define PW_PROXY_STATE			33

#define PW_ACCT_STATUS_TYPE		40
#define PW_ACCT_DELAY_TIME		41
#define PW_ACCT_INPUT_OCTETS		42
#define PW_ACCT_OUTPUT_OCTETS		43
#define PW_ACCT_SESSION_ID		44
#define PW_ACCT_AUTHENTIC		45
#define PW_ACCT_SESSION_TIME		46
#define PW_ACCT_INPUT_PACKETS		47
#define PW_ACCT_OUTPUT_PACKETS		48
#define PW_ACCT_TERMINATE_CAUSE		49

#define PW_EVENT_TIMESTAMP		55

#define PW_CHAP_CHALLENGE		60
#define PW_NAS_PORT_TYPE		61
#define PW_PORT_LIMIT			62

#define PW_ARAP_PASSWORD		70
#define PW_ARAP_FEATURES		71
#define PW_ARAP_ZONE_ACCESS		72
#define PW_ARAP_SECURITY		73
#define PW_ARAP_SECURITY_DATA		74
#define PW_PASSWORD_RETRY		75
#define PW_PROMPT			76
#define PW_CONNECT_INFO			77
#define PW_CONFIGURATION_TOKEN		78
#define PW_EAP_MESSAGE                  79
#define PW_MESSAGE_AUTHENTICATOR        80

#define PW_ARAP_CHALLENGE_RESPONSE	84
#define PW_NAS_PORT_ID_STRING  		87
#define PW_FRAMED_POOL			88

#define PW_DIGEST_RESPONSE		206
#define PW_DIGEST_ATTRIBUTES		207

#define PW_FALL_THROUGH			500
#define PW_ADD_PORT_TO_IP_ADDRESS	501
#define PW_EXEC_PROGRAM			502
#define PW_EXEC_PROGRAM_WAIT		503

#define PW_AUTH_TYPE			1000
#define PW_PREFIX			1003
#define PW_SUFFIX			1004
#define PW_GROUP			1005
#define PW_CRYPT_PASSWORD		1006
#define PW_CONNECT_RATE			1007
#define PW_ADD_PREFIX			1008
#define PW_ADD_SUFFIX			1009
#define PW_EXPIRATION			1010
#define PW_AUTZ_TYPE			1011
#define PW_ACCT_TYPE			1012
#define PW_SESSION_TYPE			1013
#define PW_POST_AUTH_TYPE		1014
#define PW_PRE_PROXY_TYPE		1015
#define PW_POST_PROXY_TYPE		1016
#define PW_PRE_ACCT_TYPE		1017
#define PW_EAP_TYPE			1018
#define PW_EAP_TLS_REQUIRE_CLIENT_CERT	1019

#define PW_USER_CATEGORY		1029
#define PW_GROUP_NAME			1030
#define PW_HUNTGROUP_NAME		1031
#define PW_SIMULTANEOUS_USE		1034
#define PW_STRIP_USER_NAME		1035
#define PW_HINT				1040
#define PAM_AUTH_ATTR			1041
#define PW_LOGIN_TIME			1042
#define PW_STRIPPED_USER_NAME		1043
#define PW_CURRENT_TIME			1044
#define PW_REALM			1045
#define PW_NO_SUCH_ATTRIBUTE		1046
#define PW_PACKET_TYPE			1047
#define PW_PROXY_TO_REALM      		1048
#define PW_REPLICATE_TO_REALM  		1049
#define PW_ACCT_SESSION_START_TIME	1050
#define PW_ACCT_UNIQUE_SESSION_ID	1051
#define PW_CLIENT_IP_ADDRESS		1052
#define PW_LDAP_USERDN			1053
#define PW_NS_MTA_MD5_PASSWORD		1054
#define PW_SQL_USER_NAME  		1055
#define PW_LM_PASSWORD			1057
#define PW_NT_PASSWORD			1058
#define PW_SMB_ACCOUNT_CTRL		1059
#define PW_SMB_ACCOUNT_CTRL_TEXT	1061
#define PW_USER_PROFILE			1062
#define PW_DIGEST_REALM			1063
#define PW_DIGEST_NONCE			1064
#define PW_DIGEST_METHOD		1065
#define PW_DIGEST_URI			1066
#define PW_DIGEST_QOP			1067
#define PW_DIGEST_ALGORITHM		1068
#define PW_DIGEST_BODY_DIGEST		1069
#define PW_DIGEST_CNONCE		1070
#define PW_DIGEST_NONCE_COUNT		1071
#define PW_DIGEST_USER_NAME		1072
#define PW_POOL_NAME			1073
#define PW_LDAP_GROUP			1074
#define PW_MODULE_SUCCESS_MESSAGE	1075
#define PW_MODULE_FAILURE_MESSAGE	1076
#define PW_X99_FAST			1077
#define PW_REWRITE_RULE			1078
#define PW_SQL_GROUP			1079
#define PW_RESPONSE_PACKET_TYPE		1080
#define PW_PACKET_DST_PORT		1081
#define PW_MS_CHAP_USE_NTLM_AUTH	1082

/*
 *	Integer Translations
 */

/*	User Types	*/

#define	PW_LOGIN_USER			1
#define	PW_FRAMED_USER			2
#define	PW_CALLBACK_LOGIN_USER		3
#define	PW_CALLBACK_FRAMED_USER		4
#define PW_OUTBOUND_USER		5
#define PW_ADMINISTRATIVE_USER		6
#define PW_NAS_PROMPT_USER		7
#define PW_AUTHENTICATE_ONLY		8
#define PW_CALLBACK_NAS_PROMPT		9

/*	Framed Protocols	*/

#define	PW_PPP				1
#define	PW_SLIP				2

/*	Framed Routing Values	*/

#define	PW_NONE				0
#define	PW_BROADCAST			1
#define	PW_LISTEN			2
#define	PW_BROADCAST_LISTEN		3

/*	Framed Compression Types	*/

#define	PW_VAN_JACOBSEN_TCP_IP		1

/*	Login Services	*/

#define	PW_TELNET			0
#define	PW_RLOGIN			1
#define	PW_TCP_CLEAR			2
#define	PW_PORTMASTER			3

/*	Authentication Level	*/

#define PW_AUTHTYPE_LOCAL		0
#define PW_AUTHTYPE_SYSTEM		1
#define PW_AUTHTYPE_SECURID		2
#define PW_AUTHTYPE_CRYPT		3
#define PW_AUTHTYPE_REJECT		4
#define PW_AUTHTYPE_ACTIVCARD		5
#define PW_AUTHTYPE_EAP                 6
#define PW_AUTHTYPE_ACCEPT		254
#define PW_AUTHTYPE_MS_CHAP		1028

/*	Port Types		*/

#define PW_NAS_PORT_ASYNC		0
#define PW_NAS_PORT_SYNC		1
#define PW_NAS_PORT_ISDN		2
#define PW_NAS_PORT_ISDN_V120		3
#define PW_NAS_PORT_ISDN_V110		4

/*	Status Types	*/

#define PW_STATUS_START			1
#define PW_STATUS_STOP			2
#define PW_STATUS_ALIVE			3
#define PW_STATUS_ACCOUNTING_ON		7
#define PW_STATUS_ACCOUNTING_OFF	8

/*
 *  Vendor Private Enterprise Codes
 */
#define VENDORPEC_FREERADIUS	11344


/*
 * Vendor specific attributes
 */
#define PW_FREERADIUS_PROXIED_TO	((VENDORPEC_FREERADIUS<<16)|1)

/*
 *  Microsoft has vendor code 311.
 */
#define PW_MSCHAP_RESPONSE	((311 << 16) | 1)
#define PW_MSCHAP_ERROR		((311 << 16) | 2)
#define PW_MSCHAP_CHALLENGE	((311 << 16) | 11)
#define PW_MSCHAP2_RESPONSE	((311 << 16) | 25)
#define PW_MSCHAP2_SUCCESS	((311 << 16) | 26)


/*
 *  Old nonsense.  Will be deleted ASAP
 */
#define PW_AUTHTYPE			1000
#define PW_AUTZTYPE			1011
#define PW_ACCTTYPE			1012
#define PW_SESSTYPE			1013
#define PW_POSTAUTHTYPE			1014
