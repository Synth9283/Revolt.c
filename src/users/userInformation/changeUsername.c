/*
 * Source file for revoltChangeUsername
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltChangeUsername(struct RevoltClient* client, const char* username, const char* password) {
    char* patchJSON = mprintf("{\"username\": \"%s\", \"password\": \"%s\"}}", username, password);
    char* patchURL = mprintf("https://api.revolt.chat/users/@me/username");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = patchRequest(patchURL, patchJSON, 1, sessionHeader);

    free(response.string);
    free(patchJSON);
    free(patchURL);
    free(sessionHeader);

    return 0;
}
