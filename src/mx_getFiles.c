#include "uls.h"

int mx_getFiles(int argc, char *argv[], int nflags, char **F) {
    int files = 0;

    for (int i = nflags + 1; i < argc; i++) {
        struct stat buff;

        if (lstat(argv[i], &buff) != -1) {
            char *mode = mx_getPermission(buff);

            if (mode[0] != 'd') {
                F[files] = argv[i];
                files++;
            }
        }
        F[files] = NULL;
    }
    return files;
}
