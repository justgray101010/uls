#include "uls.h"

static void print_permissions(t_file *file);
static void printacl(t_file *file);
static void print_links(t_file *file, t_file **files);
static void print_user(t_file *file, t_file **files, int *cur_flag);

void mx_1l(t_file **files, int c, int *cur_flag) {
    mx_printinode(files[c], files, cur_flag);
    print_permissions(files[c]);
    printacl(files[c]);
    print_links(files[c], files);
    print_user(files[c], files, cur_flag);
}

static void print_permissions(t_file *file) {
    mx_printstr(file->permissions);
}

static void printacl(t_file *file) {
    mx_printchar(file->acl);
    mx_printstr(" ");
}

static void print_links(t_file *file, t_file **files) {
    mx_space(mx_getmaxlinks(files) - mx_strlen(file->links));
    mx_printstr(file->links);
    mx_printstr(" ");
}

static void print_user(t_file *file, t_file **files, int *cur_flag) {
    if (!cur_flag[8]) {
        mx_printstr(file->user);
        mx_space(mx_getmaxuser(files) - mx_strlen(file->user));
        mx_printstr("  ");
    }
}
