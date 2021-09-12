/*
 * Source file for revoltCompleteOnboarding
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltCompleteOnboarding(struct RevoltClient* client, char* username) {
    char* postURL = mprintf("https://api.revolt.chat/onboard/complete");
    char* postJSON = mprintf("{\"username\": \"%s\"}", username);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = postRequest(postURL, postJSON, 1, sessionHeader);

    free(response.string);
    free(postURL);
    free(postJSON);
    free(sessionHeader);

    return 0;
}
