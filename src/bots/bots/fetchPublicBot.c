/*
 * Source file for fetchPublicBot
*/

#include <string.h>
#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltFetchPublicBot(struct RevoltClient* client, struct RevoltPublicBot* publicBot, const char* bot) {
    char* getURL = mprintf("https://api.revolt.chat/bots/%s/invite", bot);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    json_extract(response.string, response.length,
                "(_id):?s,"
                "(username):?s,"
                "(avatar._id):?s,"
                "(avatar.tag):b,"
                "(avatar.size):d,"
                "(avatar.filename):?s,"
                "(avatar.metadata.type):?s,"
                "(avatar.content_type):?s,"
                "(description):?s",
                &publicBot->id,
                &publicBot->username,
                &publicBot->avatar->id,
                &publicBot->avatar->tag,
                &publicBot->avatar->size,
                &publicBot->avatar->metadata->type,
                &publicBot->avatar->contentType,
                &publicBot->description
                );

    if (!strcmp(publicBot->avatar->metadata->type, "File")) {
        json_extract(response.string, response.length,
                    "(avatar.metadata.type):?s",
                    &publicBot->avatar->metadata->file->type
                    );
    }

    else if (!strcmp(publicBot->avatar->metadata->type, "Text")) {
        json_extract(response.string, response.length,
                    "(avatar.metadata.type):?s",
                    &publicBot->avatar->metadata->text->type
                    );
    }
    else if (!strcmp(publicBot->avatar->metadata->type, "Audio")) {
        json_extract(response.string, response.length,
                    "(avatar.metadata.type):?s",
                    &publicBot->avatar->metadata->audio->type
                    );
    }
    else if (!strcmp(publicBot->avatar->metadata->type, "Image")) {
        json_extract(response.string, response.length,
                    "(avatar.metadata.type):?s,"
                    "(avatar.metadata.width):d,"
                    "(avatar.metadata.height):d",
                    &publicBot->avatar->metadata->image->type,
                    &publicBot->avatar->metadata->image->width,
                    &publicBot->avatar->metadata->image->height
                    );
    }
    else if (!strcmp(publicBot->avatar->metadata->type, "Video")) {
        json_extract(response.string, response.length,
                    "(avatar.metadata.type):?s,"
                    "(avatar.metadata.width):d,"
                    "(avatar.metadata.height):d",
                    &publicBot->avatar->metadata->video->type,
                    &publicBot->avatar->metadata->video->width,
                    &publicBot->avatar->metadata->video->height
                    );
    }

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
