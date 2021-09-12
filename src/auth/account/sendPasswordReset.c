/*
 * Source file for sendPasswordReset
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltSendPasswordReset(struct RevoltPasswordResetData* data) {
    char* postURL = mprintf("https://api.revolt.chat/account/reset_password");
    char* postJSON = mprintf("{\"email\": \"%s\", \"captcha\": \"%s\"}", data->email, data->captcha);

    struct SizedBuffer response = postRequest(postURL, postJSON, 0);

    free(response.string);
    free(postURL);
    free(postJSON);

    return 0;
}
