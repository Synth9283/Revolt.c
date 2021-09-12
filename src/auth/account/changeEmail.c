/*
 * Source file for changeEmail
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltChangeEmail(struct RevoltClient* client, struct RevoltChangeEmailData* data) {
    char* postURL = mprintf("https://api.revolt.chat/account/change/email");
    char* postJSON = mprintf("{\"current_password\": \"%s\", \"email\": \"%s\"}", data->currentPassword, data->email);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = postRequest(postURL, postJSON, 1, sessionHeader);

    free(response.string);
    free(postURL);
    free(postJSON);
    free(sessionHeader);

    return 0;
}
