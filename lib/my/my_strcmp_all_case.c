/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** jj
*/

#include <stdlib.h>
#include "my.h"

int my_strcmp_all_case(char const *s1, char const *s2)
{
    char *str1 = my_str_lower_case(my_strdup(s1));
    char *str2 = my_str_lower_case(my_strdup(s2));
    int diff = 0;

    if (str1 == NULL || str2 == NULL)
        return 124;
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]){
            diff = str1[i] - str2[i];
            free(str1);
            free(str2);
            return diff;
        }
    }
    free(str1);
    free(str2);
    return 0;
}
