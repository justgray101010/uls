#include "uls.h"

void mx_printFiles(t_input input, char **F, int *cur_flags) {
    if (input.files) {
        if (!input.prior[0] && !input.prior[7] 
            && !input.prior[11] && !input.prior[8]) {
            if (!isatty(1))
                mx_catEPrint(F, cur_flags, ".");
            else if (input.prior[13])
                mx_1print(F, cur_flags, ".");
            else
                mx_standartout(F, input.files, cur_flags, ".");
        }
        else
            mx_l(F, cur_flags, ".");
        if (input.dirs) 
            mx_printstr("\n");
    }
}
