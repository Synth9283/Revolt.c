/*
 * Source file for revoltSendMessage
*/

#include "../deps/revolt.h"
#include "../deps/ulid/ulid.h"
#include "../deps/json-utils/utils.h"

int revoltSendMessage(struct RevoltClient* client, const char* message, const char* target) {
    char ulidBuffer[32] = {0};
    struct ulid_generator generator = {0};

    ulid_generator_init(&generator, ULID_SECURE);
    ulid_generate(&generator, ulidBuffer);

    char* postJSON = mprintf("{\"content\": \"%s\", \"nonce\": \"%i\"}", message, ulidBuffer);
    char* postURL = mprintf("https://api.revolt.chat/channels/%s/messages/", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = postRequest(postURL, postJSON, 2, sessionHeader, useridHeader);

    free(response.string);
    free(postJSON);
    free(postURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}

