/*
 * Source file for revoltGetUserMutualFriends, which retrieves lists of
 * mutual servers and friends that the authenticated user is in with
 * another user.
*/

#include "revolt.h"
#include "deps/json-utils/utils.h"
#include "deps/cee-utils/json-actor.h"

int revoltGetUserMutualFriends(struct RevoltClient* client, const char* target, struct RevoltMutuals* buffer) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/mutual", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* userIdHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, 2, sessionHeader, userIdHeader);

    return 0;
}
