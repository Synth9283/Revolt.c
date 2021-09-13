/*
 * Source file for editSession
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltEditSession(struct RevoltClient* client, struct RevoltSession* session, const char* friendlyName) {
    char* patchURL = mprintf("https://api.revolt.chat/auth/sessions/%s", session->session);
    char* patchJSON = mprintf("{\"friendly_name\": \"%s\"}", friendlyName);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = patchRequest(patchURL, patchJSON, 1, sessionHeader);

    free(response.string);
    free(patchURL);
    free(patchJSON);
    free(sessionHeader);

    return 0;
}
