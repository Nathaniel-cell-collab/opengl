/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** strcmp
*/

#include "amazed.h"
int my_strcmp(char *src, char *cmp)
{
    int i = 0;

    if (!src || !cmp)
        return 0;
    if (my_strlen(src) != my_strlen(cmp))
        return 0;
    while (src[i] != '\0') {
        if (src[i] != cmp[i])
            return 0;
        i++;
    }
    return 1;
}
