#include "uls.h"

int *mx_getCurrentFlags(char *flags) {
    int *currentFlags = malloc(sizeof(int) * mx_strlen(flags));

    for (int i = 0; i < mx_strlen(flags); i++)
        currentFlags[i] = 0;
    return currentFlags;
}
