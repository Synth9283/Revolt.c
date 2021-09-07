/*
 * Source file for passwordReset
*/

#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"

int revoltPasswordReset(struct RevoltConfirmPasswordResetData* data) {
    char* postURL = mprintf("https://api.revolt.chat/auth/reset");
    char* postJSON = mprintf("{\"password\": \"%s\", \"token\": \"%s\"}", data->password, data->token);

    struct SizedBuffer response = postRequest(postURL, postJSON, 0);

    free(response.string);
    free(postURL);
    free(postJSON);

    return 0;
}
