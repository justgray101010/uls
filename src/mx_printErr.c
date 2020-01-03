#include "uls.h"

void mx_printErr(t_input input, char **E) {
    int i = 0;

    if (input.errors)
        while (E[i] != NULL) {
            DIR *d = opendir(E[i]);
            if (d == NULL) {
            char *str = mx_strnew(1);

            str = mx_strjoin(str, "uls: ");
            str = mx_strjoin(str, E[i]);
            perror(str);
            }
            i++;
        }
}
