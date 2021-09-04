#ifndef REVOLT_API_H
#define REVOLT_API_H

/*
 * A Revolt client that holds the token and userid of the user
 * that is signed in.
*/
struct RevoltClient {
    char* token;
    char* userid;
};

/*
 * Holds information about the metadata of a user's avatar.
*/
struct RevoltAvatarMetadata {
    int height;
    char* type;
    int width;
};

/*
 * Holds information about a user's avatar.
*/
struct RevoltAvatarInfo {
    char* id;
    char* contentType;
    char* filename;
    struct RevoltAvatarMetadata* metadata;
    int size;
    char* tag;
};

/*
 * Holds information about a user.
*/
struct RevoltUserInfo {
    char* id;
    struct RevoltAvatarInfo* avatar;
    int badges;
    int online;
    struct RevoltUserRelation** relations;
    char* relationship;
    char* username;
};

/*
 * Holds information about a user's relation to another user.
*/
struct RevoltUserRelation {
    char* id;
    char* status;
};

/*
 * Sends a message to the private message, channel, or group with
 * the corresponding id.
 *
 * @param client: the Revolt client
 * @param message: the message to send
 * @param target: id of the location to send the message to
 * @return: HTTP status code
*/
int revoltSendMessage(struct RevoltClient* client, const char* message, const char* target);

/*
 * Retrieves information about a user with the provided id, and
 * writes it to a buffer.
 *
 * @param client: the Revolt client
 * @param target: the id of the user to use
 * @param buffer: the buffer to write the user information to
 * @return: HTTP status code
*/
int revoltGetUserInfo(struct RevoltClient* client, const char* target, struct RevoltUserInfo* buffer);

/*
 * Frees the structure containing user information.
 *
 * @param buffer: the buffer to free
*/
void revoltFreeUserInfo(struct RevoltAvatarInfo* buffer);

#endif
