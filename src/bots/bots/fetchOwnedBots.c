/*
 * Source file for fetchOwnedBots
*/

#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltFetchOwnedBots(struct RevoltClient* client, struct RevoltOwnedBots* bots) {
    char* getURL = mprintf("https://api.revolt.chat/bots/@me");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    json_extract(response.string, response.length,
                "(bots):F,"
                "(users):F",
                &botsFromListJSON,
                &bots->bots,
                &usersFromListJSON,
                &bots->users
                );

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
