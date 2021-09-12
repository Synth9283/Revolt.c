/*
 * Source file for fetching a message from Revolt.
*/

#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltQueryNode(struct RevoltNode* node) {
    char* getURL = mprintf("https://api.revolt.chat/");

    struct SizedBuffer response = getRequest(getURL, "", 0);

    json_extract(response.string, response.length,
                "(revolt):?s,"
                "(features.registration):b,"
                "(features.captcha.enabled):b,"
                "(features.captcha.key):?s,"
                "(features.email):b,"
                "(features.invite_only):?s,"
                "(features.autumn.enabled):b,"
                "(features.autumn.url):?s,"
                "(features.january.enabled):b,"
                "(features.january.url):?s,"
                "(features.voso.enabled):b,"
                "(features.voso.url):?s,"
                "(features.voso.ws):?s,"
                "(ws):?s,"
                "(app):?s,"
                "(vapid):?s",
                &node->revolt,
                &node->features->registration,
                &node->features->captcha->enabled,
                &node->features->captcha->key,
                &node->features->email,
                &node->features->invite_only,
                &node->features->autumn->enabled,
                &node->features->autumn->url,
                &node->features->january->enabled,
                &node->features->january->url,
                &node->features->voso->enable,
                &node->features->voso->url,
                &node->features->voso->ws,
                &node->ws,
                &node->app,
                &node->vapid
                );

    free(response.string);
    free(getURL);

    return 0;
}
