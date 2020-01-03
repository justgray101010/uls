#include "uls.h"

char *mx_sortFlags(int len, char *str)  {
    char *str1 = mx_strnew(len);
    
    str1 = mx_strcpy(str1, str);
    for (int i = 1; i < len ; i++)
        for (int j = 0; j < len - i ; j++)
            if (str1[j] > str1[j + 1] && str1[j + 1] != '1')  {
                char temp = str1[j];
                str1[j] = str1[j + 1];
                str1[j + 1] = temp;
            }
    return str1;
}
