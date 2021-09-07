/*
 * Source file for fetchAccount
*/

#include "../deps/revolt.h"
#include "../deps/cee-utils/json-actor.h"
#include "../deps/json-utils/utils.h"

int revoltFetchAccount(struct RevoltClient* client, struct RevoltAccountInfo* accountInfo) {
    char* getURL = mprintf("https://api.revolt.chat/auth/user");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, "", 2, sessionHeader, useridHeader);

    json_extract(response.string, response.length,
                "(id):?s,"
                "(email):?s",
                &accountInfo->id,
                &accountInfo->email
                );

    free(response.string);
    free(getURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
