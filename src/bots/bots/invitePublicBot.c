/*
 * Source file for invitePublicBot
*/

#include "../../deps/revolt.h"
#include "../../deps/json-utils/utils.h"

int revoltInvitePublicBot(struct RevoltClient* client, struct RevoltInvitePublicBotData* data, const char* bot, enum RevoltInviteTo inviteTo) {
    char* postURL = mprintf("https://api.revolt.chat/bots/%s/invite", bot);
    char* postJSON = NULL;

    switch (inviteTo) {
        case SERVER: postJSON = mprintf("{\"server\": \"%s\"}", data->server);
        case GROUP: postJSON = mprintf("{\"group\": \"%s\"}", data->group);
    }

    char* sessionHeader = mprintf("x-session-token: %s", client->token);

    struct SizedBuffer response = postRequest(postURL, postJSON, 1, sessionHeader);

    free(response.string);
    free(postURL);
    free(sessionHeader);

    return 0;
}
