/*
 * JSON functions for converting dynamically sized lists to structures.
*/

#include "revolt.h"
#include "../deps/cee-utils/ntl.h"
#include "../deps/json-utils/utils.h"
#include "../deps/cee-utils/json-actor.h"

void attachmentFromJSON(char* json, size_t length, void* attachmentPtr) {
    struct RevoltAttachment* attachment = attachment;

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
