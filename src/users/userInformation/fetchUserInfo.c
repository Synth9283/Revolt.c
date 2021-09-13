/*
 * Source file for revoltFetchUserInfo
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"
#include "../../deps/cee-utils/json-actor.h"

int revoltFetchUserInfo(struct RevoltClient* client, struct RevoltUserInfo* userInfo, const char* user) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s", user);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    NTL_T(struct RevoltUserRelation) relations = NULL;

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    userInfo->avatar = calloc(1, sizeof(struct RevoltImageInfo));
    userInfo->avatar->metadata = calloc(1, sizeof(struct RevoltImageMetadata));

    json_extract(response.string, response.length,
                "(_id):?s,"
                "(username):?s,"
                "(avatar._id):?s,"
                "(avatar.content_type):?s,"
                "(avatar.filename):?s,"
                "(avatar.metadata.height):d,"
                "(avatar.metadata.type):?s,"
                "(avatar.metadata.width):d,"
                "(avatar.size):d,"
                "(avatar.tag):?s,"
                "(relations):F,"
                "(badges):d,"
                "(status.text):?s,"
                "(status.presence):?s,"
                "(relationship):?s,"
                "(online):b,"
                "(flags):d,"
                "(bot.owner):s",
                &userInfo->id,
                &userInfo->username,
                &userInfo->avatar->id,
                &userInfo->avatar->contentType,
                &userInfo->avatar->filename,
                &userInfo->avatar->metadata->height,
                &userInfo->avatar->metadata->type,
                &userInfo->avatar->metadata->width,
                &userInfo->avatar->size,
                &userInfo->avatar->tag,
                relationsFromJSON,
                &relations,
                &userInfo->badges,
                &userInfo->status->text,
                &userInfo->status->presence,
                &userInfo->relationship,
                &userInfo->online,
                &userInfo->flags,
                &userInfo->bot->owner
                );

    userInfo->relations = relations;

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}

void revoltFreeUserInfo(struct RevoltUserInfo* userInfo) {
    ntl_free((ntl_t) userInfo->relations, free);

    free(userInfo->id);
    free(userInfo->relationship);
    ntl_free((ntl_t) userInfo->relations, free);
    free(userInfo->username);

    free(userInfo->avatar->id);
    free(userInfo->avatar->tag);
    free(userInfo->avatar->filename);
    free(userInfo->avatar->contentType);
    free(userInfo->avatar->metadata->type);
    free(userInfo->avatar->metadata);
    free(userInfo->avatar);

}
