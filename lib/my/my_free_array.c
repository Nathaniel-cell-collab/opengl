/*
** EPITECH PROJECT, 2025
** my_free_array
** File description:
** frre all the element of an array
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

void my_free_array(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        free(array[i]);
        array[i] = NULL;
        i++;
    }
    if (array != NULL)
        free(array);
}
