/*
 * Source file for revoltFetchUserProfile, which retrieves the profile for a
 * Revolt user with an id.
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"
#include "../../deps/cee-utils/json-actor.h"

int revoltFetchMutualFriends(struct RevoltClient* client, struct RevoltUsers* users, const char* user) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/mutual", user);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    NTL_T(struct sized_buffer) userList = NULL;

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    json_extract(response.string, response.length,
                "(users):?L",
                &userList
                );

    stringsFromListJSON(users->users, userList);

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
