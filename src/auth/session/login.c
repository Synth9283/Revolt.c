/*
 * Source file for revoltLogin
*/

#include "../../deps/revolt.h"
#include "../../deps/cee-utils/json-actor.h"
#include "../../deps/json-utils/utils.h"

int revoltLogin(struct RevoltLoginData* data, struct RevoltLoginSession* session) {
    char* postURL = mprintf("https://api.revolt.chat/session/login");
    char* postJSON = mprintf("{\"email\": \"%s\", \"password\": \"%s\", \"challenge\": \"%s\", \"friendly_name\": \"%s\", \"captcha\": \"%s\"}", data->email, data->password, data->challenge, data->friendly_name, data->captcha);

    struct SizedBuffer response = postRequest(postURL, postJSON, 0);
    
    json_extract(response.string, response.length,
                "(_id):?s,"
                "(user_id):?s,"
                "(token):?s,"
                "(name):?s,"
                "(subscription):?s",
                &session->id,
                &session->userId,
                &session->token,
                &session->name,
                &session->subscription
                );

    free(response.string);
    free(postURL);
    free(postJSON);

    return 0;
}
