/*
** EPITECH PROJECT, 2024
** my_evil_array
** File description:
** reverse a string and display it
*/

#include <stddef.h>
#include "my.h"

int my_len_array(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}

char **my_evil_array(char **array)
{
    int s = 0;
    int e = my_len_array(array) - 1;
    char *tmp;

    while (s < e) {
        tmp = array[s];
        array[s] = array[e];
        array[e] = tmp;
        e = e - 1;
        s = s + 1;
    }
    return array;
}
