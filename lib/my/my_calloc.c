/*
** EPITECH PROJECT, 2025
** my_calloc
** File description:
** my_calloc
*/

#include "my.h"
#include <stdlib.h>

void *my_calloc(void *op, int set, int size)
{
    op = malloc(size);
    if (!op)
        return NULL;
    my_memset(op, set, size);
    return op;
}
