/*
 * Source file for revoltLogin
*/

#include "../deps/revolt.h"
#include "../deps/cee-utils/json-actor.h"
#include "../deps/json-utils/utils.h"

int revoltLogin(struct RevoltLoginData* data, struct RevoltLoginSession* session) {
    char* postURL = mprintf("https://api.revolt.chat/auth/login");
    char* postJSON = mprintf("{\"email\": \"%s\", \"password\": \"%s\", \"device_name\": \"%s\", \"captcha\": \"%s\"}", data->email, data->password, data->device_name, data->captcha);

    struct SizedBuffer response = postRequest(postURL, postJSON, 0);
    
    json_extract(response.string, response.length,
                "(id):?s,"
                "(user_id):?s,"
                "(session_id):?s",
                &session->id,
                &session->user_id,
                &session->session_token
                );

    free(response.string);
    free(postURL);
    free(postJSON);

    return 0;
}
