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
 * Revolt file metadata
*/
struct RevoltFile {
    char* type;
};

/*
 * Revolt text metadata
*/
struct RevoltText {
    char* type;
};

/*
 * Revolt audio metadata
*/
struct RevoltAudio {
    char* type;
};

/*
 * Revolt image metadata
*/
struct RevoltImage {
    char* type;
    int width;
    int height;
};


/*
 * Revolt Video metadata
*/
struct RevoltVideo {
    char* type;
    int width;
    int height;
};

/*
 * Holds Revolt metadata objects
*/
struct RevoltMetadata {
    char* type;
    struct RevoltFile* file;
    struct RevoltText* text;
    struct RevoltAudio* audio;
    struct RevoltImage* image;
    struct RevoltVideo* video;
};

/*
 * A Revolt client that holds the token and userid of the user
 * that is signed in.
*/
struct RevoltClient {
    char* token;
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
    char* challenge;
    char* friendly_name;
    char* captcha;
};

/*
 * The loggin session data recieved after logging in
*/
struct RevoltLoginSession {
    char* id;
    char* userId;
    char* token;
    char* name;
    char* subscription;
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
    char* currentPassword;
};

/*
 * The data required for changing a Revolt user email
*/
struct RevoltChangeEmailData {
    char* currentPassword;
    char* email;
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
    char* session;
    char* friendlyName;
};

/*
 * Holds Revolt attachment data
*/
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

/*
 * Holds Revolt embed data
*/
struct RevoltEmbed {
    char* type;
};

/*
 * Holds Revolt channel member data
*/
struct RevoltChannelMember {
    struct {
        char* server;
        char* user;
    } id;
    char* nickname;
    struct RevoltImageInfo* avatar;
    char** roles;
};

/*
 * Holds Revolt message content data
*/
struct RevoltMessageContent {
    char* type;
    char* content;
};

/*
 * Holds Revolt edited message data
*/
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
    struct RevoltBot* bot;
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
struct RevoltBot {
    char* id;
    char* owner;
    char* token;
    int _public;
    char* interactionsUrl;
};

/*
 * Holds information about a public bot avatar
*/
struct RevoltPublicBotAvatar {
    char* id;
    char* tag;
    int size;
    char* filename;
    struct RevoltMetadata* metadata;
    char* contentType;
};

/*
 * Holds public bot data
*/
struct RevoltPublicBot {
    char* id;
    char* username;
    struct RevoltPublicBotAvatar* avatar;
    char* description;
};

/*
 * Holds data for creating a bot
*/
struct RevoltBotCreateData {
    char* name;
};

/*
 * Holds data for fetching owned bots
*/
struct RevoltOwnedBots {
    struct RevoltBot** bots;
    struct RevoltUserInfo** users;
};

/*
 * Holds the data for fetching a owned bot
*/
struct RevoltOwnedBot {
    struct RevoltBot* bot;
    struct RevoltUserInfo* user;
};

/*
 * Holds the data for editing a bot
*/
struct RevoltEditBotData {
    char* name;
    int _public;
    char* interactionsUrl;
    char* remove;
};

/*
 * Holds the data for inviting a public bot
*/
struct RevoltInvitePublicBotData {
    char* server;
    char* group;
};

/*
 * Holds the data for a web push subscription
*/
struct RevoltSubscribeData {
    char* endpoint;
    char* p256dh;
    char* auth;
};

/*
 * Bitfields for editing a user object
*/
enum RevoltUserEditObject {
    STATUS = 0x01,
    PROFILE = 0x02,
    AVATAR = 0x04
};

/*
 * Bitfields for inviting a public bot
*/
enum RevoltInviteTo {
    SERVER = 0x01,
    GROUP = 0x02
};

#endif
