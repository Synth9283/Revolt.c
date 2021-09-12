/*
 * Source file for editing a message from Revolt.
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltEditMessage(struct RevoltClient* client, struct RevoltMessage* message, const char* content) {
    char* patchURL = mprintf("https://api.revolt.chat/channels/%s/messages/%s", message->channel, message->id);
    char* patchJSON = mprintf("{\"content\": \"%s\"}", content);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = patchRequest(patchURL, patchJSON, 1, sessionHeader);

    free(response.string);
    free(patchURL);
    free(patchJSON);
    free(sessionHeader);

    return 0;
}
