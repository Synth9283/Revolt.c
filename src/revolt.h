#ifndef REVOLT_API_H
#define REVOLT_API_H

struct RevoltClient {
    char* token;
    char* userid;
};

struct RevoltAvatarMetadata {
    int height;
    char* type;
    int width;
};

struct RevoltAvatarInfo {
    char* id;
    char* contentType;
    char* filename;
    struct RevoltAvatarMetadata* metadata;
    int size;
    char* tag;
};

struct RevoltUserInfo {
    char* id;
    struct RevoltAvatarInfo* avatar;
    int badges;
    int online;
    struct RevoltUserRelation** relations;
    char* relationship;
    char* username;
};

struct RevoltUserRelation {
    char* id;
    char* status;
};

int revoltSendMessage(struct RevoltClient* client, const char* message, const char* target);
int revoltGetUserInfo(struct RevoltClient* client, const char* target, struct RevoltUserInfo* buffer);

#endif
