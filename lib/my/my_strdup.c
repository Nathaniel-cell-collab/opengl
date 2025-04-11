/*
** EPITECH PROJECT, 2024
** strdup
** File description:
** dup
*/

#include <unistd.h>
#include <stdlib.h>
#include "amazed.h"

char *my_strdup(char const *src)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    if (new_str == NULL)
        return NULL;
    while (src[i] != '\0') {
        new_str[i] = src[i];
        i = i + 1;
    }
    new_str[i] = '\0';
    return new_str;
}
