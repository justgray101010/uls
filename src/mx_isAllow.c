#include "uls.h"

void mx_isAllow(char *Directory) {
    while (mx_strchr(Directory, '/') != 0) {
        Directory = mx_strchr(Directory, '/');
        Directory++;
    }
    char *str = mx_strnew(1);
    str = mx_strjoin(str,"uls: ");
    str = mx_strjoin(str,Directory);
    perror(str);
}
