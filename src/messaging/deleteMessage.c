/*
 * Source file for deleting a message from Revolt.
*/

#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"

int revoltDeleteMessage(struct RevoltClient* client, struct RevoltMessage* message) {
    char* delURL = mprintf("https://api.revolt.chat/channels/%s/messages/%s", message->channel, message->id);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = deleteRequest(delURL, "", 2, sessionHeader, useridHeader);

    free(response.string);
    free(delURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
