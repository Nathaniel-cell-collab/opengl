/*
** EPITECH PROJECT, 2024
** my_sort_array
** File description:
** file wich contains all the function wich sort an array
*/

#include "my.h"
#include <stddef.h>

char **alphabetical_sort(char **sorted_array)
{
    char *tmp;

    for (int j = 0; sorted_array[j + 1] != NULL; j++) {
        if (my_strcmp(sorted_array[j], sorted_array[j + 1]) == -124)
            return NULL;
        if (my_strcmp(sorted_array[j], sorted_array[j + 1]) > 0) {
            tmp = sorted_array[j];
            sorted_array[j] = sorted_array[j + 1];
            sorted_array[j + 1] = tmp;
        }
    }
    return sorted_array;
}

char **my_sort_array(char **array)
{
    char **sorted_array = array;

    for (int i = 0; sorted_array[i] != NULL; i++) {
        sorted_array = alphabetical_sort(sorted_array);
        if (sorted_array == NULL)
            return NULL;
    }
    return sorted_array;
}
