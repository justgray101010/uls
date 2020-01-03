#include "uls.h"

static void setinfo(t_file *file, char *F, char *Directory, int *cur_flag);
static time_t gettime(struct stat buff, int *cur_flag);
static char *getpath(char *File, char *Directory);
static struct stat getstat(char *path);

t_file **mx_getFinfo(t_file **files, char **F,
char *Directory, int *cur_flag) {
    int i = 0;

    while (F[i] != NULL) {
        files[i] = malloc(sizeof(t_file));
        setinfo(files[i], F[i], Directory, cur_flag);
        i++;
    }
    files[i] = NULL;
    return files;
}

static void setinfo(t_file *file, char *F, char *Directory, int *cur_flag) {
    time_t cur_time = time(0);
    char *path = getpath(F, Directory);
    struct stat buff = getstat(path);
    time_t time = gettime(buff, cur_flag);

    file->path = path;
    file->filename = F;
    file->permissions = mx_getPermission(buff);
    file->acl = mx_getacl(path, path);
    file->links = mx_itoa(buff.st_nlink);
    file->user = mx_getuser(buff, cur_flag);
    file->group = mx_getgroup(buff, cur_flag);
    file->time = mx_gettime(time);
    file->stime = mx_getstime(time, cur_time);
    file->size = mx_getsize(buff);
    file->inode = mx_sizetoa(buff.st_ino);
}

static char *getpath(char *File, char *Directory) {
    char *path = malloc(sizeof(char *));

    if (!mx_strcmp(Directory, "."))
        path = File;
    else {
        path = mx_strjoin(path,Directory);
        path = mx_strjoin(path,"/");
        path = mx_strjoin(path,File);
    }
    return path;
}

static struct stat getstat(char *path) {
    struct stat buff;

    lstat(path, &buff);
    return buff;
}

static time_t gettime(struct stat buff, int *cur_flag) {
    time_t time;

    if (cur_flag[6]) // u
        time = buff.st_atime;
    else
        time = buff.st_mtime;
    return time;
}
