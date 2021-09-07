/*
 * Source file for changeEmail
*/

#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"

int revoltChangeEmail(struct RevoltClient* client, struct RevoltChangeEmailData* data) {
    char* postURL = mprintf("https://api.revolt.chat/auth/change/email");
    char* postJSON = mprintf("{\"password\": \"%s\", \"new_email\": \"%s\"}", data->password, data->newEmail);
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
