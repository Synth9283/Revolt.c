/*
 * Source file for revoltGetUserProfile, which retrieves the profile for a
 * Revolt user with an id.
*/

#include "revolt.h"
#include "deps/json-utils/utils.h"
#include "deps/cee-utils/json-actor.h"

int revoltGetUserProfile(struct RevoltClient* client, const char* target, struct RevoltUserProfile* buffer) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/profile", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, 2, sessionHeader, useridHeader);

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
                 &buffer->content);

    return 0;
}
