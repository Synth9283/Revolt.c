/*
 * Source file for polling message changes from Revolt.
*/

#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltPollMessageChanges(struct RevoltClient* client, struct RevoltMessageChange *messageChange, const char** ids, const char* channel) {
    char* postURL = mprintf("https://api.revolt.chat/channels/%s/messages/stale", channel);
    char* postJSON = mprintf("{\"ids\":[\"%s\"]}", ids);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = postRequest(postURL, postJSON, 1, sessionHeader);

    json_extract(response.string, response.length,
                "(changed._id):?s,"
                "(changed.nonce):?s,"
                "(changed.channel):?s,"
                "(changed.author):?s,"
                "(changed.content.type):?s,"
                "(changed.content.content):?s,"
                "(changed.attachements._id):?s,"
                "(changed.attachments.tag):?s,"
                "(changed.attachments.size):d,"
                "(changed.attachments.filename):?s,"
                "(changed.attachments.metadata.type):?s,"
                "(changed.attachments.content_type):?s,"
                "(changed.edited.$date):?s,"
                "(changed.embeds.type):?s,"
                "(changed.mentions):?s,"
                "(changed.replies):?s,"
                "(deleted):?s",
                &messageChange->id,
                &messageChange->nonce,
                &messageChange->channel,
                &messageChange->author,
                &messageChange->content->type,
                &messageChange->content->content,
                &messageChange->attachments->id,
                &messageChange->attachments->tag,
                &messageChange->attachments->size,
                &messageChange->attachments->filename,
                &messageChange->attachments->metadata->type,
                &messageChange->attachments->content_type,
                &messageChange->edited->date,
                &message->embeds->type,
                &message->mentions,
                &message->replies,
                &message->deleted
                );

    free(response.string);
    free(postURL);
    free(postJSON)
    free(sessionHeader);

    return 0;
}
