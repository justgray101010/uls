#include "uls.h"

static int getMaxLength(int *cur_flag, char **F, t_file **files, int n_files);
static int countLines(int n_files, int max);
static char *getPath(char *File, char *Dir);
static int getMaxSpace(int max);

void mx_standartout(char **F, int n_files, int *cur_flag, char *dir) {
    t_file **files = (t_file **)malloc(sizeof(t_file) * 500000);
    files = mx_getFinfo(files, F, dir, cur_flag);
    int max = getMaxLength(cur_flag, F, files, n_files);
    int count = countLines(n_files, max);
    char *path;
    int vars[2];

    for (vars[0] = 0; vars[0] < count; vars[0]++)
        for (vars[1] = 0; vars[1] < n_files; vars[1]++)
            if (vars[1] == vars[0] || ((vars[1] - vars[0]) % count == 0)) {
                path = getPath(F[vars[1]], dir);
                mx_printinode(files[vars[1]], files, cur_flag);
                mx_printname(files[vars[1]], cur_flag);
                if (vars[1] + count >= n_files)
                    mx_printstr("\n");
                else
                    mx_defSpace(cur_flag, vars[1], max, files);
            }
    free(files);
}

static char *getPath(char *File, char *Dir) {
    char *path = malloc(sizeof(char *));
    path = mx_strjoin(path, Dir);
    path = mx_strjoin(path, "/");
    path = mx_strjoin(path, File);
    return path;
}

static int getMaxLength(int *cur_flag, char **F, t_file **files, int n_files) {
    int max = 0;

    if (!cur_flag[3]) {
        for (int i = 0; i < n_files; i++)
            if (mx_strlen(F[i]) > max)
                max = mx_strlen(F[i]);
    }
    else 
        for (int i = 0;i < n_files; i++)
            if(mx_strlen(F[i]) + mx_strlen(files[i]->inode) + 1 > max)
                max = mx_strlen(F[i]) + mx_strlen(files[i]->inode) + 1;
    return max;
}

static int countLines(int n_files, int max) {
    int win_col = mx_getwinsize();
    int count = 1;
    int space = getMaxSpace(max);
    int c_words;
    int add;

    if (n_files * (max + space) >= win_col) {
        c_words = win_col / (max + space);
        if (c_words == 0)
            c_words++;
        add = 0;
        if ((n_files % c_words) != 0)
            add++;
        count = (n_files / c_words) + add;
    }
    if (!n_files)
        count = 0;
    return count;
}

int mx_getwinsize() {
    struct winsize w;
    ioctl(1, _IOR('t', 104, struct winsize), &w);
    int win_col = w.ws_col;

    return win_col;
}

static int getMaxSpace(int max) {
    int tmp;
    int space;

    tmp = max - 8;
    if (tmp < 0) {
        space = 8 - max;
        return space;
    }
    while (tmp > 8) 
        tmp -= 8;
    space = 8 - tmp;
    return space; 
}
