/*
 * Source file for fetching a message from Revolt.
*/

#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"

int revoltFetchMessage(struct RevoltClient* client, struct RevoltFetchMessageParams* params) {
    char* getURL = mprintf("https://api.revolt.chat/channels/%s/messages/%s", params->channel, params->message);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, "", 2, sessionHeader, useridHeader);

    free(response.string);
    free(getURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
