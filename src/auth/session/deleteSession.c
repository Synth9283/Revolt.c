/*
 * Source file for deleteSession
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltDeleteSession(struct RevoltClient* client, const char* session) {
    char* delURL = mprintf("https://api.revolt.chat/auth/sessions/%s", session);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = deleteRequest(delURL, "", 1, sessionHeader);

    free(response.string);
    free(delURL);
    free(sessionHeader);

    return 0;
}
