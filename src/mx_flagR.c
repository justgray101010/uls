#include "uls.h"

static char *get_path(char *File, char *Directory);

void mx_flagR(char **F, t_input input, char *Dir, int dir_count) {
    if (input.cur_flags[3])
        for (int i = 0; i < dir_count; i++) {
            char *path = get_path(F[i], Dir);
            struct stat buff;
            
            lstat(path, &buff);
            char *mod = mx_getPermission(buff);

            if (mod[0] == 'd' && (mx_strcmp(F[i], ".") != 0 
                && mx_strcmp(F[i], "..") != 0)) {
                char **Drec = malloc(sizeof(char *) * 200);
                mx_printstr("\n");
                mx_printstr(path);
                mx_printstr(":\n");
                Drec[0] = path;
                Drec[1] = NULL;
                mx_printDirs(input, Drec, input.cur_flags);
                free(Drec);
            }
        }
}

static char *get_path(char *File, char *Directory) {
    char *path = malloc(sizeof(char *));
    path = mx_strjoin(path,Directory);
    path = mx_strjoin(path,"/");
    path = mx_strjoin(path,File);
    return path;
}
