/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** jj
*/

#include <stdlib.h>

int my_strncmp(char const *s1, char const *s2, int size)
{
    for (int i = 0; i < size; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
