/*
 * Source file for fetchBot
*/

#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltFetchBot(struct RevoltClient* client, struct RevoltOwnedBot* ownedBot, const char* bot) {
    char* getURL = mprintf("https://api.revolt.chat/bots/%s", bot);
    char* sessionHeader = mprintf("x-session-token: %s", client->token);
    NTL_T(struct RevoltUserRelation) relations = NULL;

    struct SizedBuffer response = getRequest(getURL, "", 1, sessionHeader);

    json_extract(response.string, response.length,
                "(bot._id):?s,"
                "(bot.owner):?s,"
                "(bot.token):?s,"
                "(bot.public):b,"
                "(bot.interaction_url)",
                "(user._id):?s,"
                "(user.username):?s,"
                "(user.avatar._id):?s,"
                "(user.avatar.content_type):?s,"
                "(user.avatar.filename):?s,"
                "(user.avatar.metadata.height):d,"
                "(user.avatar.metadata.type):?s,"
                "(user.avatar.metadata.width):d,"
                "(user.avatar.size):d,"
                "(user.avatar.tag):?s,"
                "(user.relations):F,"
                "(user.badges):d,"
                "(user.status.text):?s,"
                "(user.status.presence):?s,"
                "(user.relationship):?s,"
                "(user.online):b,"
                "(user.flags):d,"
                "(user.bot.owner):s",
                &ownedBot->bot->id,
                &ownedBot->bot->owner,
                &ownedBot->bot->token,
                &ownedBot->bot->_public,
                &ownedBot->bot->interactionsUrl,
                &ownedBot->user->id,
                &ownedBot->user->username,
                &ownedBot->user->avatar->id,
                &ownedBot->user->avatar->contentType,
                &ownedBot->user->avatar->filename,
                &ownedBot->user->avatar->metadata->height,
                &ownedBot->user->avatar->metadata->type,
                &ownedBot->user->avatar->metadata->width,
                &ownedBot->user->avatar->size,
                &ownedBot->user->avatar->tag,
                relationsFromJSON,
                &relations,
                &ownedBot->user->badges,
                &ownedBot->user->status->text,
                &ownedBot->user->status->presence,
                &ownedBot->user->relationship,
                &ownedBot->user->online,
                &ownedBot->user->flags,
                &ownedBot->user->bot->owner
                );

    ownedBot->user->relations = relations;

    free(response.string);
    free(getURL);
    free(sessionHeader);

    return 0;
}
