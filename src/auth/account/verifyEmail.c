/*
 * Source file for verifyEmail
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltVerifyEmail(const char* code) {
    char* postURL = mprintf("https://api.revolt.chat/account/verify/%s", code);

    struct SizedBuffer response = postRequest(postURL, "", 0);

    free(response.string);
    free(postURL);

    return 0;
}
