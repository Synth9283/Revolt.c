/*
 * Source file for fetching messages from Revolt.
*/

#include "../deps/types.h"
#include "../deps/revolt.h"
#include "../deps/ulid/ulid.h"
#include "../deps/json-utils/utils.h"

int revoltFetchMessage(struct RevoltClient* client, struct RevoltMessage* message, const char* target, struct RevoltFetchMessagesParams* params) {
    char ulidBuffer[32] = {0};
    struct ulid_generator generator = {0};

    ulid_generator_init(&generator, ULID_SECURE);
    ulid_generate(&generator, ulidBuffer);

    char* getJSON = mprintf("{\"limit\": %d, \"before\": \"%s\", \"after\": \"%s\", \"sort\": \"%s\", \"nearby\": \"%s\", \"include_users\": %d}", params->limit, params->before, params->after, params->sort, params->nearby, params->includeUsers);
    char* getURL = mprintf("https://api.revolt.chat/channels/\"%s\"/messages", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, getJSON, 2, sessionHeader, useridHeader);

    json_extract(response.string, response.length,
                "(_id):?s,"
                "(nonce):d,"
                "(channel):?s,"
                "(author):?s,"
                "(content.type):?s,"
                "(content.content):?s,"
                "(attachements._id):?s,"
                "(attachements.tag):?s,"
                "(attachements.size):d,"
                "(atttachements.filename):?s,"
                "(attachements.metadata.type):?s,"
                "(attachements.content_type):?s,"
                "(edited.$date):?s,"
                "(embed.type):?s,"
                "(mentions):?s,"
                "(replies):?s",
                &message->id,
                &message->nonce,
                &message->channel,
                &message->author,
                &message->content.type,
                &message->content.content,
                &message->attachments->id,
                &message->attachments->tag,
                &message->attachements->size,
                &message->attachements->filename,
                &message->attachements->metadata.type,
                &message->attachments->contentType,
                &message->edited.date,
                &message->embed->type,
                &message->mentions,
                &message->replies
                )

    free(response.string);
    free(getJSON);
    free(getURL);
    free(sessionHeader);
    free(useridHeader);

    return 0;
}
