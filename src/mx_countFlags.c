#include "uls.h"

static void no_allow(char *flags, int i, int j, char *argv[]);
static void check(int i, char *argv[], char *flags, int *current_flags);

int mx_countFlags(int argc, char *argv[], char *flags, int *current_flags) {
    int nflags = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || !argv[i][1])
            break;
        if (argv[i][1] == '-' && !argv[i][2]) {
            nflags++;
            break;
        }
        nflags++;
        check(i, argv, flags, current_flags);
    }
    return nflags;
}

static void check(int i, char *argv[], char *flags, int *current_flags) {
    for (int j = 1; j < mx_strlen(argv[i]); j++) {
        bool a = 0;

        for (int k = 0; k < mx_strlen(flags); k++)
            if (argv[i][j] == flags[k]) {
                a++;
                current_flags[k] = 1;
            }
        if (!a)
            no_allow(flags, i, j, argv);
    }
}

static void no_allow(char *flags, int i, int j, char *argv[]) {
    char *illegal = mx_strnew(1);
    char *sortflags = mx_sortFlags(mx_strlen(flags), flags);

    mx_printerr("uls: illegal option -- ");
    illegal[0] = argv[i][j];
    mx_printerr(illegal);
    free(illegal);
    mx_printerr("\n");
    mx_printerr("usage uls [-");
    mx_printerr(sortflags);
    mx_printerr("] [file ...]");
    mx_printerr("\n");
    exit(1);
}
