/*
 * Source file for checkAuth
*/

#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"

int revoltCheckAuth(struct RevoltClient* client) {
    char* getURL = mprintf("https://api.revolt.chat/auth/check");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, "", 2, sessionHeader, useridHeader);

    free(response.string);
    free(getURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
