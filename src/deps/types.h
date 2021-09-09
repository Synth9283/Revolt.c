/*
 * Structures that are used by the API endpoints.
*/

#ifndef REVOLT_TYPES_H
#define REVOLT_TYPES_H

#define REVOLT_FETCH_LATEST "Latest"
#define REVOLT_FETCH_OLDEST "Oldest"

/*
 * A Revolt captcha struct
*/
struct RevoltCaptcha {
    int enabled;
    char* key;

};

/*
 * A Revolt autumn file server struct
*/
struct RevoltAutumn {
    int enabled;
    char* url;
};

/*
 * A Revolt january proxy server struct
*/
struct RevoltJanuary {
    int enabled;
    char* url;
};

/*
 * A Revolt voso voice server struct
*/
struct RevoltVoso {
    int enable;
    char* url;
    char* ws;
};

/*
 * A struct containing Revolt feature objects
*/
struct RevoltFeatures {
    int registration;
    struct RevoltCaptcha* captcha;
    int email;
    char* invite_only;
    struct RevoltAutumn* autumn;
    struct RevoltJanuary* january;
    struct RevoltVoso* voso;
};

/*
 * A Revolt node that holds information about which features are enabled on the remote node
*/
struct RevoltNode {
    char* revolt;
    struct RevoltFeatures* features;
    char* ws;
    char* app;
    char* vapid;
};

/*
 * A Revolt client that holds the token and userid of the user
 * that is signed in.
*/
struct RevoltClient {
    char* token;
    char* userid;
};

struct RevoltString {
    char* data;
};

/*
 * The data required for creating a Revolt account
*/
struct RevoltCreateData {
    char* email;
    char* password;
    char* invite;
    char* captcha;
};

/*
 * The data required for logging into a Revolt account
*/
struct RevoltLoginData {
    char* email;
    char* password;
    char* device_name;
    char* captcha;
};

/*
 * The loggin session data recieved after logging in
*/
struct RevoltLoginSession {
    char* id;
    char* user_id;
    char* session_token;
};

/*
 * The data required for when resetting the password
*/
struct RevoltPasswordResetData {
    char* email;
    char* captcha;
};

/*
 * The data required for when confirming a password reset
*/
struct RevoltConfirmPasswordResetData {
    char* password;
    char* token;
};

/*
 * The data required for changing a Revolt user password
*/
struct RevoltChangePasswordData {
    char* password;
    char* newPassword;
};

/*
 * The data required for changing a Revolt user email
*/
struct RevoltChangeEmailData {
    char* password;
    char* newEmail;
};

/*
 * The account info data
*/
struct RevoltAccountInfo {
    char* id;
    char* email;
};

/*
 * The session data
*/
struct RevoltSession {
    char* id;
    char* friendlyName;
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

struct RevoltMessageContent {
    char* type;
    char* content;
};

struct RevoltMessageEdited {
    char* date;
};

/*
 * Used for storing the message object from Revolt
*/
struct RevoltMessage {
    char* id;
    char* nonce;
    char* channel;
    char* author;
    struct RevoltMessageContent* content;
    struct RevoltAttachment** attachments;
    struct RevoltMessageEdited* edited;
    struct RevoltEmbed** embeds;
    char** mentions;
    char** replies;
    
};

/*
 * Used for fetching channel messages from Revolt
*/
struct RevoltChannelMessages {
    struct RevoltMessage *message;
    struct RevoltUserInfo** users;
    struct RevoltChannelMember** members;
};

/*
 * Used for fetching message changes from Revolt
*/
struct RevoltMessageChange {
    char* id;
    char* nonce;
    char* channel;
    char* author;
    struct RevoltMessageContent* content;
    struct RevoltAttachment** attachments;
    struct RevoltMessageEdited* edited;
    struct RevoltEmbed** embeds;
    char** mentions;
    char** replies;
    char** deleted;
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
 * Holds the list of users
*/
struct RevoltUsers {
    char** users;
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
