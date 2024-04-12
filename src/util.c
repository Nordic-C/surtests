#include "util.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

bool canRunTest(const char name[]) {
    const char *env = getenv("SURTUR_TESTS");
    if (env[0] == '*')
        return true;
    size_t len = 0;
    if (env != NULL) {
        char **tests = parseEnvVar(env, &len);
        for (int i = 0; i < len; i++) {
            char* testName = tests[i];
            if (!strcmp(testName, name)) {
                return true;
            }
        }
    }
    return false;
}