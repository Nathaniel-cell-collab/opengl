/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** jj
*/
#include "my.h"
#include <stdlib.h>

void my_strncat(char *dest, char const *src, int nb)
{
    int start = my_strlen(dest);

    for (int i = nb; src[i] != '\0'; i++) {
        dest[start] = src[i];
        start++;
    }
    dest[start] = 0;
}
