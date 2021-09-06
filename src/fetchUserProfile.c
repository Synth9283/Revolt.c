/*
 * Source file for revoltFetchUserProfile, which retrieves the profile for a
 * Revolt user with an id.
*/

#include "deps/revolt.h"
#include "deps/json-utils/utils.h"
#include "deps/cee-utils/json-actor.h"

int revoltFetchUserProfile(struct RevoltClient* client, const char* target, struct RevoltUserProfile* buffer) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/profile", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* userIdHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, 2, sessionHeader, userIdHeader);

    buffer->background = calloc(1, sizeof(struct RevoltImageInfo));
    buffer->background->metadata = calloc(1, sizeof(struct RevoltImageMetadata));

    json_extract(response.string, response.length,
                 "(background._id):?s,"
                 "(background.content_type):?s,"
                 "(background.filename):?s,"
                 "(background.metadata.height):d,"
                 "(background.metadata.type):?s,"
                 "(background.metadata.width):d,"
                 "(background.size):d,"
                 "(background.tag):?s,"
                 "(content):?s",
                 &buffer->background->id,
                 &buffer->background->contentType,
                 &buffer->background->filename,
                 &buffer->background->metadata->height,
                 &buffer->background->metadata->type,
                 &buffer->background->metadata->width,
                 &buffer->background->size,
                 &buffer->background->tag,
                 &buffer->content
                );

    free(getURL);
    free(sessionHeader);
    free(userIdHeader);
    free(response.string);

    return 0;
}

void revoltFreeUserProfile(struct RevoltUserProfile* buffer) {
    free(buffer->background->id);
    free(buffer->background->contentType);
    free(buffer->background->filename);
    free(buffer->background->metadata->type);
    free(buffer->background->tag);
    free(buffer->content);

    free(buffer->background->metadata);
    free(buffer->background);
}
