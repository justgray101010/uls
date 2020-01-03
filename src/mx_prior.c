#include "uls.h"

int *mx_prior(char *flags, char **argv, int nflags) {
    int *prioFlags = malloc(sizeof(int) * mx_strlen(flags));
    int l = mx_strlen(flags);
    char *p = {"logn1C\0"};
    int arr[5];

    for (arr[0] = 0; arr[0] < l; arr[0]++)
        prioFlags[arr[0]] = 0;
    for (arr[1] = 1; arr[1] <= nflags; arr[1]++)
        for (arr[2] = 1; arr[2] < mx_strlen(argv[arr[1]]); arr[2]++)
            for (arr[3] = 0; arr[3] < l; arr[3]++)
                if (argv[arr[1]][arr[2]] == flags[arr[3]]
                    && mx_get_char_index(p, flags[arr[3]]) >= 0) {
                    for (arr[4] = 0; arr[4] < l; arr[4]++)
                        prioFlags[arr[4]] = 0;
                    prioFlags[arr[3]] = 1;
                    }
    return prioFlags;
}
