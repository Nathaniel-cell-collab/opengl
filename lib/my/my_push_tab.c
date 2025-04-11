/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** my_realloc
*/

#include "amazed.h"

char **my_push_tab(char **src, char *to_push)
{
    char **new_array = NULL;
    int i = 0;

    if (!src)
        return NULL;
    new_array = malloc(sizeof(char *) * (my_array_len(src) + 2));
    if (!new_array)
        return NULL;
    while (src[i] != NULL) {
        new_array[i] = my_strdup(src[i]);
        if (!new_array[i])
            return NULL;
        i = i + 1;
    }
    new_array[i] = my_strdup(to_push);
    if (!new_array[i])
            return NULL;
    new_array[i + 1] = NULL;
    my_free_array(src);
    return new_array;
}
