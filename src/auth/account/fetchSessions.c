/*
 * Source file for fetchSessions
*/

#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltFetchSessions(struct RevoltClient* client, struct RevoltSession** sessions) {
    char* getURL = mprintf("https://api.revolt.chat/auth/sessions");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    NTL_T(struct RevoltSession) sessionsList = NULL;

    json_extract(response.string, response.length,
                "[F]",
                sessionsFromJSON,
                &sessions
                );

    sessions = sessionsList;

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
