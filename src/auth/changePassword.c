/*
 * Source file for changePassword
*/

#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"

int revoltChangePassword(struct RevoltClient* client, struct RevoltChangePasswordData* data) {
    char* postURL = mprintf("https://api.revolt.chat/auth/change/password");
    char* postJSON = mprintf("{\"password\": \"%s\", \"new_password\": \"%s\"}", data->password, data->newPassword);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = postRequest(postURL, postJSON, 2, sessionHeader, useridHeader);

    free(response.string);
    free(postURL);
    free(postJSON);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
