#include "uls.h"

void mx_printname(t_file *file, int *cur_flag) {
    char *type = file->permissions;

    mx_printstr(file->filename);
    if (cur_flag[9] && type[0] == 'd')
        mx_printstr("/");
}


