#ifndef ULS_H
#define ULS_H

#include <stdio.h>
#include <wchar.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <time.h>
#include "inc/libmx.h"

typedef struct s_file {
    char *path;
    char *filename;
    char *permissions;
    char acl;
    char *links;
    char *user;
    char *group;
    char *time;
    char *stime;
    char *size;
    char *inode;
} t_file;

typedef struct s_input {
    int nflags;
    int errors;
    int files;
    int dirs;
    int *prior;
    int *cur_flags;
} t_input;

typedef struct s_array {
    char **F;
    char **D;
    char **E;
} t_array;

int mx_atoi(const char *str);
bool mx_isspace(char c);
char *mx_strcat(char *restrict s1, const char *restrict s2);
int mx_strlen(const char *s);
char *mx_itoa(int number);
int mx_strcmp(const char *s1, const char *s2);
void mx_del_strarr(char ***arr);
void mx_printchar(char c);
char *mx_strcpy(char *dst, const char *src);
char *mx_strndup(const char *s1, size_t n);
char *mx_file_to_str(const char *file);
void mx_printerr(const char *s);
void mx_strdel(char **str);
char *mx_strnew(const int size);
int mx_get_char_index(const char *str, char c);
void mx_printint(int n);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
bool mx_isdigit(int c);
void mx_printstr(const char *s);
char *mx_strjoin(const char *s1, const char *s2);
bool mx_isalpha(int c);
char *mx_strchr(const char *s, int c);
char *mx_strncpy(char *dst, const char *src, int len);

int *mx_getCurrentFlags(char *flags);
// //get arr 0000000000000.length=length.flags
char *mx_sortFlags(int len, char *str); 
// //sort str
int mx_countFlags(int argc, char *argv[], char *flags, int *cur_flags);
// //count_flags
int mx_getErrors(int argc, char *argv[],  int nflags, char **E);
// //get err
char *mx_getPermission(struct stat file_stat);
// //get drwxrwrwrwrwrwrwrwrwr
int mx_getFiles(int argc, char *argv[], int nflags, char **F);
// //files
int mx_getDirs(int argc, char *argv[], int nflags, char **D);
// //dirs
void mx_backsort(char **array, int left, int right);
// //sort input -r
void mx_sorting(t_array array, t_input input, int *cur_flag);
// //sort input
void mx_printErr(t_input input, char **E);
// //XD
int *mx_prior(char *flags, char **argv, int n_flags);
// //prioritet 
char mx_getacl(char *filename, char *path);
// // @ + ' '
char *mx_getuser(struct stat buff, int *cur_flag);
// //get mbashenko
char *mx_getgroup(struct stat buff, int *cur_flag);
// //4242
char *mx_gettime(time_t time);
// //
char *mx_getstime(time_t time, time_t cur_time);
// //T
char *mx_getsize(struct stat buff);
// //get size for finfo in bits
t_file **mx_getFinfo(t_file **file, char **F,
char *Directory, int *cur_flag);
// //file info
void mx_space(int count);
// //prints ' '
void mx_printinode(t_file *file, t_file **files, int *cur_flags);
// //inode
void mx_1l(t_file **files, int c, int *cur_flag);
// //first part l
void mx_2l(t_file **files, int c, int *cur_flag);
// //sec part l
void mx_l(char **F, int *cur_flag, char *Directory);
// //l flag
void mx_printFiles(t_input input, char **F, int *cur_flags);
// //print files from input
char *mx_sizetoa(size_t number);
// //XD
int mx_getmaxgroup(t_file **all);
// //4242
int mx_getmaxlinks(t_file **files);
// //get max length links
int mx_getmaxuser(t_file **files);
// //len mbashenko
int mx_getmaxtime(t_file **files);
// //time len
int mx_getmaxsize(t_file **files);
// //size
void mx_printname(t_file *file, int *cur_flag);
// // print name file
void mx_catEPrint(char **F, int *cur_flags, char *dir);
// //cat -e
void mx_1print(char **F, int *cur_flags, char *dir);
// // 1print
void mx_defSpace(int *cur_flags, int j, int max, t_file **files);
// //
void mx_standartout(char **F, int n_files, int *cur_flag, char *dir);
// //standart
// //read dir if more then ls .
char **mx_readdir(int *cur_flag, DIR *direct, int *dir_count, int j);
// //read dir F
void mx_getAll(char **F, char *Dir);
// //get files
void mx_printDirs(t_input input, char **D, int *cur_flag);
// //print dirs
void mx_isAllow(char *Directory);

void mx_sort(char **F, int *cur_flag, int dir_count, int noterr);

void mx_flagR(char **F, t_input input, char *Dir, int dir_count);
// //R
int mx_getwinsize();


#endif 
