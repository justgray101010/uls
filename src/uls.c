#include "uls.h"

static t_array *mallocarray(int argc);
static t_input *readinput(int argc, char **argv, t_array array, char *flags);
static int *get_currentFlags(int argc, char *argv[], 
t_input input, char *flags);

// system("leaks -q out");
//l0 A1 a2 i3 R4 r5 u6 n7 g8 C9 p10 o11 T12  113
int main(int argc, char *argv[]) {
    t_array *array = mallocarray(argc);
    char *flags = {"lAaiRrungCpoT1\0"};
    t_input *input = readinput(argc, argv, *array, flags);
    int *cflags = get_currentFlags(argc, argv, *input, flags);

    input->cur_flags = cflags;
    mx_sorting(*array, *input, cflags);
    mx_printErr(*input, array->E);
    mx_printFiles(*input, array->F, cflags);
    mx_printDirs(*input, array->D, cflags);
    free(input);
    free(cflags);
}

static t_input *readinput(int argc, char **argv, t_array array, char *flags) {
    t_input *input = malloc(sizeof(t_input));
    int nflags = 0;
    int *current_flags = mx_getCurrentFlags(flags);

    nflags = mx_countFlags(argc, argv, flags, current_flags);
    input->nflags = nflags;
    input->errors = mx_getErrors(argc, argv, nflags, array.E);
    input->files = mx_getFiles(argc, argv, nflags, array.F);
    input->dirs = mx_getDirs(argc, argv, nflags, array.D);
    input->prior = mx_prior(flags, argv, nflags);
    return input;
}

static int *get_currentFlags(int argc, char *argv[], 
t_input input, char *flags) {
    int *cur_flags = mx_getCurrentFlags(flags);

    input.nflags = mx_countFlags(argc, argv, flags, cur_flags);
    return cur_flags;
}

static t_array *mallocarray(int argc) {
    t_array *array = malloc(sizeof(t_array));
    char **F = (char **)malloc(sizeof(char *) * argc);
    char **D = (char **)malloc(sizeof(char *) * argc);
    char **E = (char **)malloc(sizeof(char *) * argc);

    array->F = F;
    array->D = D;
    array->E = E;
    return array;
}
