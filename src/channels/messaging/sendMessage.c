/*
 * Source file for revoltSendMessage
*/

#include "../../deps/revolt.h"
#include "../../deps/ulid/ulid.h"
#include "../../deps/json-utils/utils.h"

int revoltSendMessage(struct RevoltClient* client, const char* message, const char* channel) {
    char ulidBuffer[32] = {0};
    struct ulid_generator generator = {0};

    ulid_generator_init(&generator, ULID_SECURE);
    ulid_generate(&generator, ulidBuffer);

    char* postJSON = mprintf("{\"content\": \"%s\", \"nonce\": \"%i\"}", message, ulidBuffer);
    char* postURL = mprintf("https://api.revolt.chat/channels/%s/messages/", channel);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = postRequest(postURL, postJSON, 1, sessionHeader);

    free(response.string);
    free(postJSON);
    free(postURL);
    free(sessionHeader);

    return 0;
}

