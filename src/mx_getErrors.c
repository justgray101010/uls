#include "uls.h"

int mx_getErrors(int argc, char *argv[], int nflags, char **E) {
    int errors = 0;

    for (int i = nflags + 1; i < argc; i++) {
        struct stat buff;

        if (lstat(argv[i], &buff) == -1) {
            E[errors] = argv[i];
            errors++;
        }
        E[errors] = NULL;
    }
    return errors;
}
