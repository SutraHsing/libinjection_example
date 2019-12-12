#include <stdio.h>
#include <strings.h>
#include <errno.h>
#include "libinjection.h"
#include "libinjection_sqli.h"

int main(int argc, const char* argv[])
{
    struct libinjection_sqli_state state;
    int issqli;

    const char* input = argv[1];
    size_t slen = strlen(input);

    /* in real-world, you would url-decode the input, etc */

    libinjection_sqli_init(&state, input, slen, FLAG_NONE);
    issqli = libinjection_is_sqli(&state);
    if (issqli) {
        fprintf(stderr, "sqli detected with fingerprint of '%s'\n", state.fingerprint);
    }
    return issqli;
}