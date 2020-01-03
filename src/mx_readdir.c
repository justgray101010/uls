#include "uls.h"

static int checkdot(char *str);

char **mx_readdir(int *cur_flag, DIR *direct, int *dir_count, int j) {
    struct dirent *dis;  
    char **F = (char **)malloc(sizeof(char *) * 200000);
    
    while ((dis = readdir(direct)) != 0) {
        if (!cur_flag[1] && !cur_flag[2]) {
            if (dis->d_name[0] != '.') {
                F[j] = (char *)malloc(sizeof(char) * 25600);
                F[j] = mx_strcpy(F[j], dis->d_name);
                j++;
            }
        }
        else if (cur_flag[2]) //a
            F[j++] = dis->d_name;
        else if (checkdot(&dis->d_name[0]))
                F[j++] = dis->d_name;
    }
    F[j] = NULL;
    *dir_count = j;
    free(dis);
    return F;
}

static int checkdot(char *str) {
    int j = mx_strlen(str);

    if (j == 2 && str[0] == '.' && str[1] == '.')
        return 0;
    if (j == 1)
        return 0;
    return 1;
}

