/*
 * Source file for revoltFetchDefaultUserAvatar, which retrieves the profile for a
 * Revolt user with an id.
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"
#include "../../deps/cee-utils/json-actor.h"

int revoltFetchDefaultUserAvatar(struct RevoltClient* client, FILE* fp, const char* user) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/default_avatar", user);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    fwrite(response.string, sizeof(char), response.length, fp);

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
