/*
 * Source file for revoltCompleteOnboarding
*/

#include "../deps/revolt.h"
#include "../deps/json-utils/utils.h"

int revoltCompleteOnboarding(struct RevoltClient* client, char* username) {
    char* postURL = mprintf("https://api.revolt.chat/onboard/complete");
    char* postJSON = mprintf("{\"username\": \"%s\"}", username);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = postRequest(postURL, postJSON, 2, sessionHeader, useridHeader);

    free(response.string);
    free(postURL);
    free(postJSON);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
