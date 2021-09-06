#include <stdlib.h>
#include "../src/revolt.h"
#include "../src/deps/cee-utils/ntl.h"

int main() {
    struct RevoltClient client = {.token = getenv("REVOLT_CLIENT_TOKEN"),
                                  .userid = getenv("REVOLT_CLIENT_USERID")};

    struct RevoltUserInfo user = {0};
    revoltGetUserInfo(&client, "01FERANRTAD5GRFKFW7G6S15AF", &user);

    printf("%s\n", user.username);
    printf("%s\n", user.relationship);
    printf("%s\n", user.id);


    for(int index = 0; index < ntl_length((ntl_t) user.relations); index++) {
        struct RevoltUserRelation* relationship = user.relations[index];

        printf("%s", relationship->id);
        printf("%s", relationship->status);
    }

    revoltFreeUserInfo(&user);
}
