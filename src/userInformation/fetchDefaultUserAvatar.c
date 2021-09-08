/*
 * Source file for revoltFetchDefaultUserAvatar, which retrieves the profile for a
 * Revolt user with an id.
*/

#include <stdio.h>
#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"
#include "../deps/cee-utils/json-actor.h"

int revoltFetchDefaultUserAvatar(struct RevoltClient* client, FILE* fp, const char* user) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/default_avatar", user);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* userIdHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, "", 2, sessionHeader, userIdHeader);

    fwrite(response.string, sizeof(char), response.length, fp);

    free(getURL);
    free(sessionHeader);
    free(userIdHeader);
    free(response.string);

    return 0;
}
