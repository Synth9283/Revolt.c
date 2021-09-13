/*
 * Source file for deleteAllSessions
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltdeleteAllSessions(struct RevoltClient* client, int revokeSelf) {
    char* delURL = mprintf("https://api.revolt.chat/session/all");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* queryHeader = NULL;
    if (revokeSelf) queryHeader = mprintf("revoke_session: true");
    else queryHeader = mprintf("revoke_session: false");

    struct SizedBuffer response = deleteRequest(delURL, "", 2, sessionHeader, queryHeader);

    free(response.string);
    free(delURL);
    free(sessionHeader);
    free(queryHeader);

    return 0;
}
