/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** concatenates two string
*/

#include <unistd.h>
#include "amazed.h"

void free_cat(char *dest, char *src, int free_bool[2])
{
    if (free_bool[0] == 1)
        my_free(dest);
    if (free_bool[1] == 1)
        my_free(src);
}

char *my_strcat(char *dest, char *src, int free_bool[2])
{
    int lenght = my_strlen(src);
    int lenghtdest = my_strlen(dest);
    int i = 0;
    int y = 0;
    char *new = malloc(sizeof(char) * (lenght + lenghtdest + 1));

    if (new == NULL)
        return NULL;
    while (dest[y] != '\0') {
        new[y] = dest[y];
        y++;
    }
    while (src[i] != '\0') {
        new[y] = src[i];
        i++;
        y++;
    }
    new[y] = '\0';
    free_cat(dest, src, free_bool);
    return new;
}
