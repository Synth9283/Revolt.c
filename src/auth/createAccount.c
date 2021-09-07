/*
 * Source file for revoltCreateAccount
*/

#include "../deps/revolt.h"
#include "../deps/cee-utils/json-actor.h"
#include "../deps/json-utils/utils.h"

int revoltCreateAccount(struct RevoltCreateData* data, const char* userId) {
    char* postURL = mprintf("https://api.revolt.chat/auth/create");
    char* postJSON = mprintf("{\"email\": \"%s\", \"password\": \"%s\", \"invite\": \"%s\", \"captcha\": \"%s\"}", data->email, data->password, data->invite, data->captcha);

    struct SizedBuffer response = postRequest(postURL, postJSON, 0);
    
    json_extract(response.string, response.length,
                "(user_id):?s",
                &userId
                );

    free(response.string);
    free(postURL);
    free(postJSON);

    return 0;
}

