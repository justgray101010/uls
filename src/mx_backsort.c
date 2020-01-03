#include "uls.h"

static void swap_str(char **s1, char **s2);


void mx_backsort(char **array, int left, int right) {
    if (left < right) {
        int low = left;
        int high = right;
        char *middle = array[(low + high) / 2];

        while (low <= high) {
            while (mx_strcmp(array[low], middle) > 0)
                low++;
            while (mx_strcmp(array[high], middle) < 0)
                high--;
            if (low <= high) {
                swap_str(&array[low],&array[high]);
                low++;
                high--;
            }
        }
        mx_backsort(array, left, high);
        mx_backsort(array, low, right);
    }
}

static void swap_str(char **s1, char **s2) {
   char *temp;
   temp = *s1;
   *s1 = *s2;
   *s2 = temp;
}
