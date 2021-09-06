/*
 * Structures that are used by the API endpoints.
*/

#ifndef REVOLT_TYPES_H
#define REVOLT_TYPES_H

#define REVOLT_FETCH_LATEST "Latest"
#define REVOLT_FETCH_OLDEST "Oldest"


/*
 * A Revolt client that holds the token and userid of the user
 * that is signed in.
*/
struct RevoltClient {
    char* token;
    char* userid;
};

struct RevoltAttachment {
    char* id;
    char* tag;
    int size;
    char* filename;
    struct {
        char* type;
    } metadata;
    char* contentType;
};

struct RevoltEmbed {
    char* type;
};

struct RevoltChannelMember {
    struct {
        char* server;
        char* user;
    } id;
    char* nickname;
    struct RevoltImageInfo* avatar;
    char** roles;
};

struct RevoltChannelMessages {
    struct {
        char* id;
        char* string;
        char* channel;
        char* author;
        struct {
            char* type;
            char* content;
        } content;
        struct RevoltAttachment** attachments;
        struct {
            char* date;
        } editied;
        struct RevoltEmbed** embeds;
        char** mentions;
        char** replies;
    } messages;
    struct RevoltUserInfo** users;
    struct RevoltChannelMember** members;
};

/*
 * Used for specifiying settings for fetching messages from Revolt
*/
struct RevoltFetchMessagesParams {
    int   limit;
    char* before;
    char* after;
    char* sort;
    char* nearby;
    int includeUsers;
};

/*
 * Used for specifiying settings for fetching a message from Revolt
*/
struct RevoltFetchMessageParams {
    char* channel;
    char* message;
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
};

#endif
