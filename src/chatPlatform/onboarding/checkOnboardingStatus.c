/*
 * Source file for revoltOnboardingStatus
*/

#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltOnboardingStatus(struct RevoltClient* client, int* onboarding) {
    char* getURL = mprintf("https://api.revolt.chat/onboard/hello");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    json_extract(response.string, response.length,
                "(onboarding):b",
                &onboarding
                );

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
