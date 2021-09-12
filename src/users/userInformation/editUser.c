/*
 * Source file for revoltEditUser
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

enum RevoltUserEditObject {
    STATUS = 0x01,
    PROFILE = 0x02,
    AVATAR = 0x04
};

int revoltEditUserStatus(struct RevoltClient* client, struct RevoltUserStatus* status) {
    char* patchJSON = mprintf("{\"status\": {\"text\": \"%s\", \"presence\": \"%s\"}}", status->text, status->presence);
    char* patchURL = mprintf("https://api.revolt.chat/users/@me");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = patchRequest(patchURL, patchJSON, 1, sessionHeader);

    free(response.string);
    free(patchJSON);
    free(patchURL);
    free(sessionHeader);

    return 0;
}

int revoltEditUserProfile(struct RevoltClient* client, struct RevoltUserProfile* profile) {
    char* patchJSON = mprintf("{\"profile\": {\"content\": \"%s\", \"background\": \"%s\"}}", profile->content, profile->background);
    char* patchURL = mprintf("https://api.revolt.chat/users/@me");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = patchRequest(patchURL, patchJSON, 1, sessionHeader);

    free(response.string);
    free(patchJSON);
    free(patchURL);
    free(sessionHeader);

    return 0;
}

int revoltEditUserAvatar(struct RevoltClient* client, const char* avatar) {
    char* patchJSON = mprintf("{\"avatar\": \"%s\"}", avatar);
    char* patchURL = mprintf("https://api.revolt.chat/users/@me");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = patchRequest(patchURL, patchJSON, 1, sessionHeader);

    free(response.string);
    free(patchJSON);
    free(patchURL);
    free(sessionHeader);

    return 0;
}

int revoltEditUserRemove(struct RevoltClient* client, enum RevoltUserEditObject object) {
    char* patchJSON = NULL;
    
    switch (object) {
        case STATUS:
            patchJSON = mprintf("{\"status\"}");
            break;
        case PROFILE:
            patchJSON = mprintf("{\"profile\"}");
            break;
        case AVATAR:
            patchJSON = mprintf("{\"avatar\"}");
            break;
    }

    char* patchURL = mprintf("https://api.revolt.chat/users/@me");
    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = patchRequest(patchURL, patchJSON, 1, sessionHeader);

    free(response.string);
    free(patchJSON);
    free(patchURL);
    free(sessionHeader);

    return 0;
}
