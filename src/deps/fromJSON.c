/*
 * JSON functions for converting dynamically sized lists to structures.
*/

#include <string.h>
#include "revolt.h"
#include "../deps/cee-utils/ntl.h"
#include "../deps/json-utils/utils.h"
#include "../deps/cee-utils/json-actor.h"

void attachmentFromJSON(char* json, size_t length, void* attachmentPtr) {
    struct RevoltAttachment* attachment = attachmentPtr;

    json_extract(json, length,
                 "(_id):?s,"
                 "(tag):?s,"
                 "(size):d,"
                 "(filename):?s,"
                 "(metadata.type):?s,"
                 "(content_type):?s",
                 &attachment->id,
                 &attachment->tag,
                 &attachment->size,
                 &attachment->filename,
                 &attachment->metadata.type,
                 &attachment->contentType);
}

void attachmentsFromJSON(char* json, size_t length, NTL_T(struct RevoltAttachment)* attachments) {
    struct ntl_deserializer deserializer = {
        .elem_size = sizeof(struct RevoltAttachment),
        .elem_from_buf = attachmentFromJSON,
        .ntl_recipient_p = (void***) attachments
    };

    extract_ntl_from_json(json, length, &deserializer);
}

void relationFromJSON(char* json, size_t length, void* relationPtr) {
    struct RevoltUserRelation* relation = relationPtr;

    json_extract(json, length,
                 "(_id):?s,"
                 "(status):?s",
                 &relation->id,
                 &relation->status
                );
}

void relationsFromJSON(char* json, size_t length, NTL_T(struct RevoltUserRelation)* relations) {
    struct ntl_deserializer deserializer = {
        .elem_size = sizeof(struct RevoltUserRelation),
        .elem_from_buf = relationFromJSON,
        .ntl_recipient_p = (void***) relations
    };

    extract_ntl_from_json(json, length, &deserializer);
}

void sessionFromJSON(char* json, size_t length, void* sessionPtr) {
    struct RevoltSession* session = sessionPtr;

    json_extract(json, length,
                "(_id):?s,"
                "(name):?s",
                &session->session,
                &session->friendlyName
                );
}

void sessionsFromJSON(char* json, size_t length, NTL_T(struct RevoltSession)* sessions) {
    struct ntl_deserializer deserializer = {
        .elem_size = sizeof(struct RevoltSession),
        .elem_from_buf = sessionFromJSON,
        .ntl_recipient_p = (void***) sessions
    };

    extract_ntl_from_json(json, length, &deserializer);
}

void botFromListJSON(char* json, size_t length, void* botPtr) {
    struct RevoltBot* bot = botPtr;
    
    json_extract(json, length,
                "(_id):?s,"
                "(owner):?s,"
                "(token):?s,"
                "(public):b,"
                "(interaction_url)",
                &bot->id,
                &bot->owner,
                &bot->token,
                bot->_public,
                bot->interactionsUrl
                );
}

void botsFromListJSON(char* json, size_t length, NTL_T(struct RevoltBot)* bots) {
    struct ntl_deserializer deserializer = {
        .elem_size = sizeof(struct RevoltBot),
        .elem_from_buf = botFromListJSON,
        .ntl_recipient_p = (void***) bots
    };

    extract_ntl_from_json(json, length, &deserializer);
}

void userFromListJSON(char* json, size_t length, void* userPtr) {
    struct RevoltUserInfo* user = userPtr;
    NTL_T(struct RevoltUserRelation) relations = NULL;

    json_extract(json, length,
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
                 &user->id,
                 &user->username,
                 &user->avatar->id,
                 &user->avatar->contentType,
                 &user->avatar->filename,
                 &user->avatar->metadata->height,
                 &user->avatar->metadata->type,
                 &user->avatar->metadata->width,
                 &user->avatar->size,
                 &user->avatar->tag,
                 relationsFromJSON,
                 &relations,
                 &user->badges,
                 &user->status->text,
                 &user->status->presence,
                 &user->relationship,
                 &user->online,
                 &user->flags,
                 &user->bot->owner
                );
    user->relations = relations;
}

void usersFromListJSON(char* json, size_t length, NTL_T(struct RevoltUserInfo)* users) {
    struct ntl_deserializer deserializer = {
        .elem_size = sizeof(struct RevoltUserInfo),
        .elem_from_buf = userFromListJSON,
        .ntl_recipient_p = (void***) users
    };

    extract_ntl_from_json(json, length, &deserializer);
}

void stringsFromListJSON(char** strArr, NTL_T(struct sized_buffer) buffer) {
    size_t bufferLen = ntl_length((ntl_t)buffer);
    if (!bufferLen) return;

    // extract to an array of strings
    strArr = malloc(bufferLen * sizeof(char*));

    for (size_t i=0; i<bufferLen; ++i) strArr[i] = strndup(buffer[i]->start, buffer[i]->size);
}

void stringFromJSON(char* json, size_t length, void* stringPtr) {
    struct RevoltString* string = (struct RevoltString*) stringPtr;

    json_extract(json, length, "(STRING_KEY_HERE):?s", &string->data);
}

void stringsFromJSON(char* json, size_t length, NTL_T(struct RevoltString)* strings) {
    struct ntl_deserializer deserializer = {
        .elem_size = sizeof(struct RevoltString),
        .elem_from_buf = relationFromJSON,
        .ntl_recipient_p = (void***) strings
    };

    extract_ntl_from_json(json, length, &deserializer);
}
