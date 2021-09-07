/*
 * Source file for fetchSessions
*/

#include "../deps/revolt.h"
#include "../deps/cee-utils/json-actor.h"
#include "../deps/json-utils/utils.h"

int revoltFetchSessions(struct RevoltClient* client, struct RevoltSession** sessions) {
    char* getURL = mprintf("https://api.revolt.chat/auth/sessions");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, "", 2, sessionHeader, useridHeader);

    json_extract(response.string, response.length,
                "(id):?s,"
                "(friendly_name):?s",
                &sessions->id,
                &sessions->email
                );

    free(response.string);
    free(getURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
