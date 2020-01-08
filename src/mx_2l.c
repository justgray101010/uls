#include "uls.h"

static void printsize(t_file *file, t_file **files, int *cur_flag);
static void printgroup(t_file *file, t_file **files, int *cur_flag);
static void printtime(t_file *file, t_file **files, int *cur_flag);
static void printlink(t_file *file);

void mx_2l(t_file **files, int c, int *cur_flag) {
    printgroup(files[c], files, cur_flag);
    printsize(files[c], files, cur_flag);
    printtime(files[c], files, cur_flag);
    mx_printname(files[c], cur_flag);
    printlink(files[c]);
    mx_printstr("\n");
}

static void printlink(t_file *file) {
    if (file->permissions[0] == 'l') { // links
        size_t linklength;
        linklength = readlink(file->path, NULL, 20000);
        if (linklength != 0) {
            char *link  = malloc(10000);
            linklength = readlink(file->path, link, linklength);
            mx_printstr(" -> ");
            mx_printstr(link);
        }
    }
}

static void printgroup(t_file *file, t_file **files, int *cur_flag) {// n
    if(!cur_flag[10]){
        mx_printstr(file->group);
        mx_space(mx_getmaxgroup(files) - mx_strlen(file->group));
        mx_printstr("  ");
    }
}

static void printsize(t_file *file, t_file **files, int *cur_flag) {
    if(cur_flag[10] && cur_flag[7])
        mx_printstr("  ");
    mx_space(mx_getmaxsize(files) - mx_strlen(file->size));
    mx_printstr(file->size);
    mx_printstr(" ");
}

static void printtime(t_file *file, t_file **files, int *cur_flag) {
    if (!cur_flag[11]) {
        mx_space(mx_getmaxtime(files) - mx_strlen(file->stime));
        mx_printstr(file->stime);
    }
    else
        mx_printstr(file->time);
    mx_printstr(" ");
}
