/*
 * Source file for deleteBot
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltDeleteBot(struct RevoltClient* client, const char* bot) {
    char* delURL = mprintf("https://api.revolt.chat/bots/%s", bot);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = deleteRequest(delURL, "", 1, sessionHeader);

    free(response.string);
    free(delURL);
    free(sessionHeader);

    return 0;
}
