/*
 * Source file for subscribe
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltSubscribe(struct RevoltClient* client, struct RevoltSubscribeData* data) {
    char* postURL = mprintf("https://api.revolt.chat/push/subscribe");
    char* postJSON = mprintf("{\"endpoint\": {}, \"p256dh\": {}, \"auth\": {}}");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = postRequest(postURL, postJSON, 1, sessionHeader);

    free(response.string);
    free(postURL);
    free(postJSON);
    free(sessionHeader);

    return 0;
}
