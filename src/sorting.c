#include "uls.h"

static void dotsort(char **array);
static void swap_str(char **s1, char **s2);

void mx_sorting(t_array array, t_input input, int *cur_flag) {
    if (input.errors)
        mx_sort(array.E, cur_flag, input.errors, 0);
    if (input.dirs)
        mx_sort(array.D, cur_flag, input.dirs, 1);
    if (input.files)
        mx_sort(array.F, cur_flag, input.files, 1);
}

void mx_sort(char **F, int *cur_flag, int dir_count, int noterr) {
    if (cur_flag[4] && noterr){ //-r
        mx_backsort(F, 0, dir_count - 1);
        if (cur_flag[2])
            dotsort(F);
    }
    else
        mx_quicksort(F, 0, dir_count - 1);
}

static void dotsort(char **array) {
    int arrlen = 0;
    int gg;

    while (array[arrlen] != NULL)
        arrlen++;
    for (int i = 0; i < arrlen;i++)
        if (mx_strcmp(array[i], ".") == 0)
            gg = i;
    swap_str(&array[gg], &array[arrlen - 1]);
    for (int i = 0; i < arrlen;i++)
        if (mx_strcmp( "..",array[i]) == 0)
            gg = i;
    swap_str(&array[gg], &array[arrlen - 2]);
}

static void swap_str(char **s1, char **s2) {
   char *temp;
   temp = *s1;
   *s1 = *s2;
   *s2 = temp;
}
