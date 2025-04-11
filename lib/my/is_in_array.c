/*
** EPITECH PROJECT, 2024
** organized
** File description:
** is_in_array
*/

#include "amazed.h"
int is_in_array(char *str, char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        if (my_strcmp(str, array[i]) == 1)
            return 1;
        i++;
    }
    return 0;
}
