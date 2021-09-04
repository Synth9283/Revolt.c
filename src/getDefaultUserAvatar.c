/*
 * Source file for revoltGetDefaultUserAvatar, which retrieves the profile for a
 * Revolt user with an id.
*/

#include <stdio.h>
#include "deps/revolt.h"
#include "deps/json-utils/utils.h"
#include "deps/cee-utils/json-actor.h"

int revoltGetDefaultUserAvatar(struct RevoltClient* client, const char* target, FILE* buffer) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/default_avatar", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* userIdHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, 2, sessionHeader, userIdHeader);

    fwrite(response.string, sizeof(char), response.length, buffer);

    free(getURL);
    free(sessionHeader);
    free(userIdHeader);
    free(response.string);

    return 0;
}
