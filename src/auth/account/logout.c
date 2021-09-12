/*
 * Source file for logout
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltLogout(struct RevoltClient* client) {
    char* getURL = mprintf("https://api.revolt.chat/auth/logout");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
