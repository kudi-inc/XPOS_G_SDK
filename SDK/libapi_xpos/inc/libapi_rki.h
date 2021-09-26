#pragma once

#include "libapi_pub.h"

#define RKI_MODE_Mosambee  1


LIB_EXPORT int rki_init( int mode);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:yangjy
Functions:rki_dukpt_load
Input : keydata
		keydata length
return: 0 Successfully , -1  FAIL      
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int rki_dukpt_load( const char *keydata ,int len );

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:lx
Functions:rki_load_key
Input : index keydata index
Output: keydata buffer
return: keydata length
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int rki_load_key(int index, char *keydata);


/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:ruansj
Functions:api_rki_proc
Input : Nothing
Output: Nothing
return: 0---succ  other value---fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int api_rki_proc();

/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:check_app_key
Input : sha256 value of app KEY 
Output: null
return: check result: 1 success 0 fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int check_app_key(unsigned char *sHashValue);
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:check_layer_key
Input : null
Output: null
return: check result: 1 success 0 fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int check_layer_key();
/*************************************************************************************
Copyright: Fujian MoreFun Electronic Technology Co., Ltd.
Author:George
Functions:check_psp_key
Input : 64bytes ASCII code,use English uppercase format, sha256 value of psp KEY 
Output: null
return: check result: 1 success 0 fail
Remarks: Nothing
*************************************************************************************/
LIB_EXPORT int check_psp_key(unsigned char *sHashValue);

LIB_EXPORT int rki_self_test();