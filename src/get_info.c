#include "uls.h"

static char *get_time(time_t time, time_t cur_time,
char *full_time, char *stime);
static char *sizereturn(struct stat buff, char *major, char *minor);
static char *nbr_to_hex(unsigned long nbr);


char mx_getacl(char *filename, char *path) {
    struct stat buff;
    char att;
    acl_t acl = NULL;
    ssize_t xattr = 0;

    lstat(path, &buff);
    acl = acl_get_file(filename, 0x00000100);
    xattr = listxattr(filename, NULL, 0, 0x0001);
    if (xattr > 0)
        att = '@';
    else if (acl != NULL && ((buff.st_mode & 0170000) != 0120000)) 
        att = '+';
    else
        att = ' ';
    acl_free(acl);
    return att;
}

char *mx_getuser(struct stat buff, int *cur_flag) {
    char *user = (char *)malloc(256);
    struct passwd* tmp = getpwuid(buff.st_uid);

    if (tmp == NULL || cur_flag[7])
        user = mx_itoa(buff.st_uid);
    else
        user = mx_strcpy(user, tmp->pw_name);
    return user;
}

char *mx_getgroup(struct stat buff, int *cur_flag) {
    char *group;
    struct group *tmp_g = getgrgid(buff.st_gid);

    if (tmp_g == NULL || cur_flag[7]) //n
        group = mx_itoa(buff.st_gid);
    else
        group = tmp_g->gr_name;
    return group;
}

char *mx_gettime(time_t time) {
    char *ftime = mx_strnew(3000);

    ftime = ctime(&time);

    char *ltime = mx_strnew(mx_strlen(ftime) - 5);

    ltime = mx_strncpy(ltime, ftime + 4, mx_strlen(ftime) - 5);
    return ltime;
}

char *mx_getstime(time_t time, time_t cur_time) {
    char *full_time = mx_strnew(3000);
    full_time = ctime(&time);
    char *stime = mx_strnew(mx_strlen(full_time) - 13);

    return get_time(time, cur_time, full_time, stime);
}

static char *get_time(time_t time, time_t cur_time,
char *full_time, char *stime) {
    if (cur_time - time < 31556926 / 2 && ((cur_time - time >= 0))) {
        stime = mx_strncpy(stime, full_time + 4,
        mx_strlen(full_time) - 13);
    }
    else {
        int m = 0;

        for (int j = 0; j < mx_strlen(full_time) - 1; j++) {
            if ((j > 3 && j < 11) || j > 19) {
                stime[m] = full_time[j];
                m++;
            }
            if (j == 11) {
                stime[m] = ' ';
                m++;
            }
        }
    }
    return stime;
}



char *mx_getsize(struct stat buff) {
    char *major = mx_itoa((buff.st_rdev >> 24) & 0xff);
    char *minor = mx_itoa(buff.st_rdev & 0xffffff);

    if ((buff.st_rdev & 0xffffff) > 999) {
        minor = nbr_to_hex(buff.st_rdev & 0xffffff);
        while (mx_strlen(minor) < 10) 
            minor = mx_strjoin("0", minor);
        minor[1] = 'x';
    }
    while (mx_strlen(major) < 3)
        major = mx_strjoin(" ", major);
    while (mx_strlen(minor) < 3)
        minor = mx_strjoin(" ", minor);
    return sizereturn(buff, major, minor);
}



static char *sizereturn(struct stat buff, char *major, char *minor) {
    char *size = mx_strnew(30);
    char *permissions = mx_getPermission(buff);

    if (permissions[0] == 'c' || permissions[0] == 'b') {
        size = mx_strjoin(size, major);
        size = mx_strjoin(size, ", ");
        size = mx_strjoin(size, minor);
    }
    else
        size = mx_sizetoa(buff.st_size);
    return size;
}

static char *nbr_to_hex(unsigned long nbr) {
    int len = 0;
    char *string = mx_strnew(len);
    char tmp;

    while (nbr) {
        int c = nbr % 16;
        nbr /= 16;
        if (c < 10)
            string[len] = c + 48;
        else
            string[len] = c + 87;
        len++;
    }
    for (int i = 0; i < len / 2; i++){
        tmp = string[i];
        string[i] = string[len - i - 1];
        string[len - i - 1] = tmp;
    }
    return string;
}

