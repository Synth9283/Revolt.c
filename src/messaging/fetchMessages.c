/*
 * Source file for fetching messages from Revolt.
*/

#include "../deps/types.h"
#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"

int revoltFetchMessage(struct RevoltClient* client, const char* target, struct RevoltFetchMessageParams* params) {
    char* getJSON = mprintf("{\"limit\": %d, \"before\": \"%s\", \"after\": \"%s\", \"sort\": \"%s\", \"nearby\": \"%s\", \"include_users\": %d}", params->limit, params->before, params->after, params->sort, params->nearby, params->includeUsers);
    char* getURL = mprintf("https://api.revolt.chat/channels/\"%s\"/messages", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, getJSON, 2, sessionHeader, useridHeader);

    free(response.string);
    free(getJSON);
    free(getURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
