#include "uls.h"

void mx_catEPrint(char **F, int *cur_flags, char *dir) {
    t_file **files = (t_file **)malloc(sizeof(t_file) * 200000);
    int c = 0;

    files = mx_getFinfo(files, F, dir, cur_flags);
    while (F[c] != NULL) {
        if (cur_flags[4]) {
            mx_printstr(files[c]->inode);
            mx_printstr(" ");
        }
        mx_printname(files[c], cur_flags);
        mx_printstr("\n");
        c++;
    }
}

void mx_1print(char **F, int *cur_flags, char *dir) {
    t_file **files = (t_file **)malloc(sizeof(t_file) * 300000);
    files = mx_getFinfo(files, F, dir, cur_flags);
    int i = 0;

    while (F[i] != NULL) {
        if (cur_flags[3]) {
            mx_printstr(files[i]->inode);
            mx_printstr(" ");
        }
            mx_printname(files[i], cur_flags);
            mx_printstr("\n");
            i++;
    }
}

void mx_l(char **F, int *cur_flag, char *Directory) {
    t_file **files = (t_file **)malloc(sizeof(t_file) * 200000);
    files = mx_getFinfo(files, F, Directory, cur_flag);
    int i = 0;
    
    while (files[i] != NULL) {
        mx_1l(files, i, cur_flag);
        mx_2l(files, i, cur_flag);
        i++;
    }
    free(files);
}
