#include "uls.h"

void mx_getAll(char **F, char *Dir) {
    int i = 0;
    int total = 0;

    while (F[i] != NULL) {
        char *path = malloc(sizeof(char *));
        struct stat buff;

        path = mx_strjoin(path, Dir);
        path = mx_strjoin(path, "/");
        path = mx_strjoin(path, F[i]);
        lstat(path, &buff);
        total += buff.st_blocks;
        i++;
    }
    mx_printstr("total ");
    mx_printstr(mx_itoa(total));
    mx_printstr("\n");
}
