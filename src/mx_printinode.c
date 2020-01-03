#include "uls.h"

static int getMaxInode(t_file **files);

void mx_printinode(t_file *file, t_file **files, int *cur_flags) {
    if (cur_flags[3]) {
        mx_space(getMaxInode(files) - mx_strlen(file->inode));
        mx_printstr(file->inode);
        mx_printstr(" ");
    }
}

static int getMaxInode(t_file **files) {
    int i = 0;
    int max_inode = 0;
    
    while (files[i] != NULL) {
        if (max_inode < mx_strlen(files[i]->inode))
            max_inode = mx_strlen(files[i]->inode);
        i++;
    }
    return max_inode;
}
