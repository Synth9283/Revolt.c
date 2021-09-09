/*
 * Source file for revoltOnboardingStatus
*/

#include "../deps/revolt.h"
#include "../deps/cee-utils/json-actor.h"
#include "../deps/json-utils/utils.h"

int revoltOnboardingStatus(struct RevoltClient* client, int* onboarding) {
    char* getURL = mprintf("https://api.revolt.chat/onboard/hello");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, "", 2, sessionHeader, useridHeader);

    json_extract(response.string, response.length,
                "(onboarding):b",
                &onboarding
                );

    free(response.string);
    free(getURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
