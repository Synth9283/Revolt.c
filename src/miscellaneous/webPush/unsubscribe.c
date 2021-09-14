/*
 * Source file for unsubscribe
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltUnsubscribe(struct RevoltClient* client) {
    char* postURL = mprintf("https://api.revolt.chat/push/unsubscribe");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = postRequest(postURL, "", 1, sessionHeader);

    free(response.string);
    free(postURL);
    free(sessionHeader);

    return 0;
}
