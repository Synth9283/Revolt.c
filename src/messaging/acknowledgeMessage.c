/*
 * Source file for acknowledging messages on Revolt.
*/

#include "../deps/revolt.h"
#include "../deps/cee-utils/json-actor.h"
#include "../deps/json-utils/utils.h"

int revoltAcknowledgeMessage(struct RevoltClient* client, const char* channel, const char* message) {
    char* putURL = mprintf("https://api.revolt.chat/channels/%s/ack/%s", channel, message);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = putRequest(putURL, "", 2, sessionHeader, useridHeader);

    free(response.string);
    free(putURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
