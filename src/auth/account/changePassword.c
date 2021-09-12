/*
 * Source file for changePassword
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltChangePassword(struct RevoltClient* client, struct RevoltChangePasswordData* data) {
    char* postURL = mprintf("https://api.revolt.chat/account/change/password");
    char* postJSON = mprintf("{\"password\": \"%s\", \"current_password\": \"%s\"}", data->password, data->currentPassword);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = postRequest(postURL, postJSON, 1, sessionHeader);

    free(response.string);
    free(postURL);
    free(postJSON);
    free(sessionHeader);

    return 0;
}
