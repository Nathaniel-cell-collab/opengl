/*
** EPITECH PROJECT, 2025
** my_memset
** File description:
** my_memset
*/

#include "my.h"

void *my_memset(void *ptr, int set, int size)
{
    for (int i = 0; i < size; i++)
        ((unsigned char *)ptr)[i] = set;
    return ptr;
}
