#include "uls.h"

static char getType(struct stat file_stat);
static char getMode(int mode, int user_type);
static char getChar(int mode, int is_exec, int is_id);

char *mx_getPermission(struct stat file_stat) {
    char *permission = mx_strnew(11);

    permission[0] = getType(file_stat); 
    permission[1] = (file_stat.st_mode & 0000400) ? 'r' : '-';
    permission[2] = (file_stat.st_mode & 0000200) ? 'w' : '-';
    permission[3] = getMode(file_stat.st_mode, 1);
    permission[4] = (file_stat.st_mode & 0000040) ? 'r' : '-';
    permission[5] = (file_stat.st_mode & 0000020) ? 'w' : '-';
    permission[6] = getMode(file_stat.st_mode, 2);
    permission[7] = (file_stat.st_mode & 0000004) ? 'r' : '-';
    permission[8] = (file_stat.st_mode & 0000002) ? 'w' : '-';
    permission[9] = getMode(file_stat.st_mode, 4);
    return permission;
}

static char getType(struct stat file_stat) {
    char result = '-';

    if ((file_stat.st_mode & 0170000) == 0020000)
        return 'c';
    if ((file_stat.st_mode & 0170000) == 0060000)
        return 'b';
    if ((file_stat.st_mode & 0170000) == 0010000)
        return 'p';
    if ((file_stat.st_mode & 0170000) == 0140000)
        return 's';
    if ((file_stat.st_mode & 0170000) == 0120000)
        return 'l';
    if ((file_stat.st_mode & 0170000) == 0040000)
        return 'd';
    return result;
}

static char getChar(int mode, int is_exec, int is_id) {
    if (mode & is_exec) {
        if (mode & is_id)
            return 's';
        else
            return 'x';
    }
    else {
        if (mode & is_id)
            return 'S';
        else
            return '-';
    }
}

static char getMode(int mode, int user_type) {
    if (user_type == 1)
        return getChar(mode, 0000100, 0004000);
    else if (user_type == 2)
        return getChar(mode, 0000010, 0002000);
    else {
        if (mode & 0000001) {
            if (mode & 0001000)
                return 't';
            else
                return 'x';
        }
        else {
            if (mode & 0001000)
                return 'T';
            else 
                return '-';
        }
    }
}
