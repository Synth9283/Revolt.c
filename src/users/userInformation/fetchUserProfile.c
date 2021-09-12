/*
 * Source file for revoltFetchUserProfile, which retrieves the profile for a
 * Revolt user with an id.
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"
#include "../../deps/cee-utils/json-actor.h"

int revoltFetchUserProfile(struct RevoltClient* client, struct RevoltUserProfile* userProfile, const char* user) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/profile", user);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    userProfile->background = calloc(1, sizeof(struct RevoltImageInfo));
    userProfile->background->metadata = calloc(1, sizeof(struct RevoltImageMetadata));

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
                 &userProfile->background->id,
                 &userProfile->background->contentType,
                 &userProfile->background->filename,
                 &userProfile->background->metadata->height,
                 &userProfile->background->metadata->type,
                 &userProfile->background->metadata->width,
                 &userProfile->background->size,
                 &userProfile->background->tag,
                 &userProfile->content
                );

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}

void revoltFreeUserProfile(struct RevoltUserProfile* userProfile) {
    free(userProfile->background->id);
    free(userProfile->background->contentType);
    free(userProfile->background->filename);
    free(userProfile->background->metadata->type);
    free(userProfile->background->tag);
    free(userProfile->content);

    free(userProfile->background->metadata);
    free(userProfile->background);
}
