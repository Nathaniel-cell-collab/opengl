/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** my_free
*/

#include "amazed.h"
void my_free_int_array(int **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        my_free(array[i]);
    my_free(array);
}
