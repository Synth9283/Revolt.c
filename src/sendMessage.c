/*
 * Source file for revoltSendMessage
*/

#include "deps/revolt.h"
#include "deps/json-utils/utils.h"

int revoltSendMessage(struct RevoltClient* client, const char* message, const char* target) {
    char* postJSON = mprintf("{\"content\": \"%s\", \"nonce\": \"2321312312312x\"}", message);
    char* postURL = mprintf("https://api.revolt.chat/channels/%s/messages/", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = postRequest(postURL, postJSON, 2, sessionHeader, useridHeader);

    free(response.string);
    free(postJSON);
    free(postURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}

