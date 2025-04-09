/*
** EPITECH PROJECT, 2025
** strcpy
** File description:
** copy a stirng into a destination
*/

#include <stddef.h>

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    if (!dest || !src)
        return NULL;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = 0;
    return dest;
}
