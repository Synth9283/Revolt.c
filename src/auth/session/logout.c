/*
 * Source file for logout
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltLogout(struct RevoltClient* client) {
    char* deleteURL = mprintf("https://api.revolt.chat/session/logout");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = deleteRequest(deleteURL, "", 1, sessionHeader);

    free(response.string);
    free(deleteURL);
    free(sessionHeader);

    return 0;
}
