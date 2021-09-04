/*
 * Source file for revoltGetUserInfo
*/

#include "revolt.h"
#include "deps/json-utils/utils.h"
#include "deps/cee-utils/json-actor.h"

void relationFromJSON(char* json, size_t length, void* relationPtr) {
    struct RevoltUserRelation* relation = relationPtr;

    json_extract(json, length,
                 "(_id):?s,"
                 "(status):?s",
                 &relation->id,
                 &relation->status);
}

void relationsFromJSON(char* json, size_t length, NTL_T(struct RevoltUserRelation)* relations) {
    struct ntl_deserializer deserializer = {
        .elem_size = sizeof(struct RevoltUserRelation),
        .elem_from_buf = relationFromJSON,
        .ntl_recipient_p = (void***) relations
    };

    extract_ntl_from_json(json, length, &deserializer);
}

int revoltGetUserInfo(struct RevoltClient* client, const char* target, struct RevoltUserInfo* buffer) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s", target);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    char* useridHeader = mprintf("x-user-id: %s", client->userid);

    struct SizedBuffer response = getRequest(getURL, 2, sessionHeader,
                                                        useridHeader);

    buffer->avatar = calloc(1, sizeof(struct RevoltAvatarInfo));
    buffer->avatar->metadata = calloc(1, sizeof(struct RevoltAvatarMetadata));
    NTL_T(struct RevoltUserRelation) relations = NULL;

    json_extract(response.string, response.length,
                 "(_id):?s,"
                 "(avatar._id):?s"
                 "(avatar.content_type):?s,"
                 "(avatar.filename):?s,"
                 "(avatar.metadata.height):d,"
                 "(avatar.metadata.type):?s,"
                 "(avatar.metadata.width):d,"
                 "(avatar.size):d,"
                 "(avatar.tag):?s,"
                 "(badges):d,"
                 "(online):b,"
                 "(relations):F,"
                 "(relationship):?s"
                 "(username):?s",
                 &buffer->id,
                 &buffer->avatar->id,
                 &buffer->avatar->contentType,
                 &buffer->avatar->filename,
                 &buffer->avatar->metadata->height,
                 &buffer->avatar->metadata->type,
                 &buffer->avatar->metadata->width,
                 &buffer->avatar->size,
                 &buffer->avatar->tag,
                 &buffer->badges,
                 &buffer->online,
                 relationsFromJSON,
                 &relations,
                 &buffer->relationship,
                 &buffer->username
                );

    buffer->relations = relations;

    free(getURL);
    free(sessionHeader);
    free(useridHeader);
    free(response.string);


    return 0;
}

void revoltFreeUserInfo(struct RevoltUserInfo* buffer) {
    ntl_free((ntl_t) buffer->relations, free);

    free(buffer->avatar->metadata);
    free(buffer->avatar);
}

