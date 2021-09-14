/*
 * Source file for deleteInvite
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltDeleteInvite(struct RevoltClient* client, const char* invite) {
    char* delURL = mprintf("https://api.revolt.chat/invites/%s", invite);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = deleteRequest(delURL, "", 1, sessionHeader);

    free(response.string);
    free(delURL);
    free(sessionHeader);

    return 0;
}
