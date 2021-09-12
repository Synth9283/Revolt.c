/*
 * Source file for fetching a message from Revolt.
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltFetchMessage(struct RevoltClient* client, struct RevoltFetchMessageParams* params) {
    char* getURL = mprintf("https://api.revolt.chat/channels/%s/messages/%s", params->channel, params->message);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
