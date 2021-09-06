/*
 * Structures that are used by the API endpoints.
*/

#ifndef REVOLT_TYPES_H
#define REVOLT_TYPES_H

/*
 * A Revolt client that holds the token and userid of the user
 * that is signed in.
*/
struct RevoltClient {
    char* token;
    char* userid;
};

/*
 * Holds information about the metadata of a user's avatar or
 * background.
*/
struct RevoltImageMetadata {
    int height;
    char* type;
    int width;
};

/*
 * Holds information about the profile of a user.
*/
struct RevoltUserProfile {
    struct RevoltImageInfo* background;
    char* content;
};

/*
 * Holds information about a user's avatar or background.
*/
struct RevoltImageInfo {
    char* id;
    char* contentType;
    char* filename;
    struct RevoltImageMetadata* metadata;
    int size;
    char* tag;
};

/*
 * Holds information about a user.
*/
struct RevoltUserInfo {
    char* id;
    char* username;
    struct RevoltImageInfo* avatar;
    struct RevoltUserRelation** relations;
    int badges;
    struct RevoltUserStatus* status;
    char* relationship;
    int online;
    int flags;
    struct RevoltBotInfo* bot;
};

/*
 * Holds information about a user's relation to another user.
*/
struct RevoltUserRelation {
    char* id;
    char* status;
};

/*
<<<<<<< HEAD:src/types.h
 * Holds information about mutual servers and friends.
*/
struct RevoltMutuals {
    char** servers;
    char** friends;
=======
 * Holds informations about a user's status.
*/
struct RevoltUserStatus {
    char* text;
    char* presence;
};

/*
 * Holds information about a bot.
*/
struct RevoltBotInfo {
    char* owner;
>>>>>>> 44b8b124c2117e29ef1b87634ea120aa71546cae:src/deps/types.h
};

#endif
