/*
 * Copyright 2014 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#pragma once

#include <s2n.h>

#define S2N_DEBUG_STR_LEN 128
extern __thread const char *s2n_debug_str;

typedef enum {
    S2N_ERR_OK,
    S2N_ERR_KEY_INIT,
    S2N_ERR_ENCRYPT,
    S2N_ERR_DECRYPT,
    S2N_ERR_MEMSET,
    S2N_ERR_MEMCPY,
    S2N_ERR_REALLOC,
    S2N_ERR_MLOCK,
    S2N_ERR_FSTAT,
    S2N_ERR_OPEN,
    S2N_ERR_MMAP,
    S2N_ERR_NULL,
    S2N_ERR_CLOSED,
    S2N_ERR_SAFETY,
    S2N_ERR_NOT_INITIALIZED,
    S2N_ERR_RANDOM_UNITIALIZED,
    S2N_ERR_OPEN_RANDOM,
    S2N_ERR_RESIZE_STATIC_STUFFER,
    S2N_ERR_RESIZE_TAINTED_STUFFER,
    S2N_ERR_STUFFER_OUT_OF_DATA,
    S2N_ERR_STUFFER_IS_FULL,
    S2N_ERR_INVALID_BASE64,
    S2N_ERR_INVALID_PEM,
    S2N_ERR_DH_COPYING_PARAMETERS,
    S2N_ERR_DH_COPYING_PUBLIC_KEY,
    S2N_ERR_DH_GENERATING_PARAMETERS,
    S2N_ERR_DH_PARAMS_CREATE,
    S2N_ERR_DH_SERIAZING,
    S2N_ERR_DH_SHARED_SECRET,
    S2N_ERR_DH_WRITING_PUBLIC_KEY,
    S2N_ERR_DH_FAILED_SIGNING,
    S2N_ERR_INVALID_PKCS3,
    S2N_ERR_HASH_DIGEST_FAILED,
    S2N_ERR_HASH_INIT_FAILED,
    S2N_ERR_HASH_INVALID_ALGORITHM,
    S2N_ERR_HASH_UPDATE_FAILED,
    S2N_ERR_HMAC_INVALID_ALGORITHM,
    S2N_ERR_SIZE_MISMATCH,
    S2N_ERR_DECODE_CERTIFICATE,
    S2N_ERR_DECODE_PRIVATE_KEY,
    S2N_ERR_KEY_MISMATCH,
    S2N_ERR_NOMEM,
    S2N_ERR_SIGN,
    S2N_ERR_VERIFY_SIGNATURE,
    S2N_ERR_ALERT_PRESENT,
    S2N_ERR_ALERT,
    S2N_ERR_CBC_VERIFY,
    S2N_ERR_CIPHER_NOT_SUPPORTED,
    S2N_ERR_BAD_MESSAGE,
    S2N_ERR_INVALID_SIGNATURE_ALGORITHM,
    S2N_ERR_INVALID_KEY_EXCHANGE_ALGORITHM,
    S2N_ERR_NO_CERTIFICATE_IN_PEM,
    S2N_ERR_NO_ALERT,
    S2N_ERR_CLIENT_MODE,
    S2N_ERR_SERVER_NAME_TOO_LONG,
    S2N_ERR_INSECURE_CLIENT,
    S2N_ERR_HANDSHAKE_STATE,
    S2N_ERR_FALLBACK_DETECTED,
    S2N_ERR_INVALID_CIPHER_PREFERENCES,
    S2N_ERR_APPLICATION_PROTOCOL_TOO_LONG,
    S2N_ERR_NO_APPLICATION_PROTOCOL,
    S2N_ERR_DRBG
} s2n_error;

#define TO_STRING(s) #s
#define STRING_(s) TO_STRING(s)
#define STRING__LINE__ STRING_(__LINE__)

#define _S2N_ERROR( x )     s2n_debug_str = "Error encountered in " __FILE__ " line " STRING__LINE__ ; s2n_errno = ( x )
#define S2N_ERROR( x )      _S2N_ERROR( ( x ) ); return -1
#define S2N_ERROR_PTR( x )  _S2N_ERROR( ( x ) ); return NULL
