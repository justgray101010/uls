#include "uls.h"

int mx_getDirs(int argc, char *argv[], int nflags, char **D) {
    int dirs = 0;

    if (argc == nflags + 1) {
        D[0] = ".";
        D[1] = NULL;
        return 0;
    }
    for (int i = nflags + 1; i < argc; i++) {
        struct stat buff;

        if (lstat(argv[i], &buff) != -1) {
            char *mode = mx_getPermission(buff);

            if (mode[0] == 'd') {
                D[dirs] = argv[i];
                dirs++;
            }
        }
        D[dirs] = NULL;
    }
    return dirs;
}
