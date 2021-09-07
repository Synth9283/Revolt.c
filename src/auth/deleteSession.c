/*
 * Source file for deleteSession
*/

#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"

int revoltDeleteSession(struct RevoltClient* client, const char* session) {
    char* delURL = mprintf("https://api.revolt.chat/auth/sessions/%s", session);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = deleteRequest(delURL, "", 2, sessionHeader, useridHeader);

    free(response.string);
    free(delURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
