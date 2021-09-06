/*
 * Source file for revoltFetchUserProfile, which retrieves the profile for a
 * Revolt user with an id.
*/

#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"
#include "../deps/cee-utils/json-actor.h"

int revoltFetchMutualFriends(struct RevoltClient* client, const char* users, const char* target) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/mutual", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* userIdHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, 2, sessionHeader, userIdHeader);

    json_extract(response.string, response.length,
                "(users):?s",
                &users
                );

    free(response.string);
    free(getURL);
    free(sessionHeader);
    free(userIdHeader);

    return 0;
}
