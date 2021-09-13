/*
 * Source file for editBot
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltEditBot(struct RevoltClient* client, struct RevoltEditBotData* data, const char* bot) {
    char* patchURL = mprintf("https://api.revolt.chat/bots/%s", bot);
    char* patchJSON = NULL;
    if (data->_public) patchJSON = mprintf("{\"name\": \"%s\", \"public\": true, \"interaction_url\": \"%s\", \"remove\": \"%s\"}", data->name, data->interactionsUrl, data->remove);
    else patchJSON = mprintf("{\"name\": \"%s\", \"public\": false, \"interaction_url\": \"%s\", \"remove\": \"%s\"}", data->name, data->interactionsUrl, data->remove);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = patchRequest(patchURL, patchJSON, 1, sessionHeader);

    free(response.string);
    free(patchURL);
    free(patchJSON);
    free(sessionHeader);

    return 0;
}
