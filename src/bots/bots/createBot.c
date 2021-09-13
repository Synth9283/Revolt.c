/*
 * Source file for createBot
*/

#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltCreateBot(struct RevoltClient* client, struct RevoltBot* bot, struct RevoltBotCreateData* data) {
    char* postURL = mprintf("https://api.revolt.chat/bots/create");
    char* postJSON = mprintf("{\"name\": \"%s\"}", data->name);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = postRequest(postURL, postJSON, 1, sessionHeader);

    json_extract(response.string, response.length,
                "(_id):?s,"
                "(owner):?s,"
                "(token):?s,"
                "(public):b,"
                "(interaction_url)",
                &bot->id,
                &bot->owner,
                &bot->token,
                &bot->_public,
                &bot->interactionsUrl
                );

    free(response.string);
    free(postURL);
    free(postJSON);
    free(sessionHeader);

    return 0;
}
