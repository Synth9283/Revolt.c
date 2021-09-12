/*
 * Source file for deleting a message from Revolt.
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltDeleteMessage(struct RevoltClient* client, struct RevoltMessage* message) {
    char* delURL = mprintf("https://api.revolt.chat/channels/%s/messages/%s", message->channel, message->id);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = deleteRequest(delURL, "", 1, sessionHeader);

    free(response.string);
    free(delURL);
    free(sessionHeader);

    return 0;
}
