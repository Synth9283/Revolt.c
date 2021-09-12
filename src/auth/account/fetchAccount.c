/*
 * Source file for fetchAccount
*/

#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltFetchAccount(struct RevoltClient* client, struct RevoltAccountInfo* accountInfo) {
    char* getURL = mprintf("https://api.revolt.chat/account");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    json_extract(response.string, response.length,
                "(id):?s,"
                "(email):?s",
                &accountInfo->id,
                &accountInfo->email
                );

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
