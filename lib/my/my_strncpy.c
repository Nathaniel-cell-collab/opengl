/*
** EPITECH PROJECT, 2025
** strcpy
** File description:
** copy a stirng into a destination
*/

#include <stddef.h>

char *my_strncpy(char *dest, char *src, int nb)
{
    int i = 0;

    if (!dest || !src)
        return NULL;
    for (i = 0; i < nb && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = 0;
    return dest;
}
