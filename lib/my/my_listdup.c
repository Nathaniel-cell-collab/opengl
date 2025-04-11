/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_listdup
*/

#include <unistd.h>
#include <stdlib.h>
#include "amazed.h"

int my_array_len(char **array)
{
    int counter = 0;

    if (!array || !*array)
        return 0;
    while (array[counter]) {
        counter++;
    }
    return counter;
}

char **my_listdup(char **src)
{
    char **new_array = NULL;
    int i = 0;

    if (!src)
        return NULL;
    new_array = malloc(sizeof(char *) * (my_array_len(src) + 1));
    if (!new_array)
        return NULL;
    while (src[i] != NULL) {
        new_array[i] = my_strdup(src[i]);
        if (!new_array[i])
            return NULL;
        i = i + 1;
    }
    new_array[i] = NULL;
    return new_array;
}
