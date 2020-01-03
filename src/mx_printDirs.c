#include "uls.h"

static void freedir(DIR *direct, char *D);
static void lOutput(int ndir, char **F, int *cur_flag, char *D);
static void dirprint(int ndir, char **F, t_input input, char *D);
static void mx_print_dirname(int n_dirs, int n_files,
int n_errors, char *dname);

void mx_printDirs(t_input input, char **D, int *cur_flag) {
    int i = 0;

    while (D[i] != NULL) {
        mx_print_dirname(input.dirs, input.files, input.errors, D[i]); 
        DIR *direct = opendir(D[i]);
        if (direct == NULL)
            mx_isAllow(D[i]);
        else {
            int ndir = 0;
            char **F = (char **)malloc(sizeof(char *) * 2000);
            F = mx_readdir(cur_flag, direct, &ndir, 0);
            mx_sort(F, cur_flag, ndir, 1);
            dirprint(ndir, F, input, D[i]);
            mx_flagR(F, input, D[i], ndir);
            free(F);
        }
        i++;
        freedir(direct, D[i]);
    }
}

static void freedir(DIR *direct, char *D) {
    if (direct != NULL)
        closedir(direct);
    if (D != NULL)
        mx_printstr("\n");
}

static void lOutput(int ndir, char **F, int *cur_flag, char *D) {
    if (ndir)
        mx_getAll(F, D);
    mx_l(F, cur_flag, D);
}

static void dirprint(int ndir, char **F, t_input input, char *D) {
    if (!input.prior[0] && !input.prior[7] 
        && !input.prior[11] && !input.prior[8]) {
        if (!isatty(1))
            mx_catEPrint(F, input.cur_flags, D);
        else if (input.prior[13])
            mx_1print(F, input.cur_flags, D);
        else
            mx_standartout(F, ndir, input.cur_flags, D);
    }
    else
        lOutput(ndir, F, input.cur_flags, D);
}

static void mx_print_dirname(int ndirs, int nfiles,
int nerrors, char *dname) {
    if (ndirs > 1 || nfiles || nerrors) {
        mx_printstr(dname);
        mx_printstr(":");
        mx_printstr("\n");
    }
}

