/*
 * Source file for revoltGetUserProfile, which retrieves the profile for a
 * Revolt user with an id.
*/

#include "revolt.h"
#include "deps/json-utils/utils.h"
#include "deps/cee-utils/json-actor.h"

int revoltGetUserProfile(struct RevoltClient* client, const char* target, char** buffer) {
    char* getURL = mprintf("https://api.revolt.chat/users/%s/profile", target);

    
}
