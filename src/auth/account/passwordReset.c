/*
 * Source file for passwordReset
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltPasswordReset(struct RevoltConfirmPasswordResetData* data) {
    char* patchURL = mprintf("https://api.revolt.chat/account/reset_password");
    char* patchJSON = mprintf("{\"password\": \"%s\", \"token\": \"%s\"}", data->password, data->token);

    struct SizedBuffer response = patchRequest(patchURL, patchJSON, 0);

    free(response.string);
    free(patchURL);
    free(patchJSON);

    return 0;
}
