#include "uls.h"

void mx_defSpace(int j, int max, t_file **files) {
    mx_space(max - mx_strlen(files[j]->filename));
    mx_printstr("\t");
}
