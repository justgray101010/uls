#include "uls.h"

void mx_defSpace(int *cur_flags, int j, int max, t_file **files) {
    if (cur_flags[3]) {
        mx_space(max - mx_strlen(files[j]->filename)
        - mx_strlen(files[j]->inode) - 1);
    }
    else
        mx_space(max - mx_strlen(files[j]->filename));
    mx_printstr("\t");
}
