/*
** EPITECH PROJECT, 2024
** my_putlen
** File description:
** gg
*/

#include "my.h"

int my_putlen(int count, int *dest)
{
    *dest = count;
    return 0;
}

int my_putlen_va(va_list list, ...)
{
    va_list blist;
    int count = 0;

    va_start(blist, list);
    count += my_putlen(va_arg(blist, int), va_arg(list, int *));
    va_end(blist);
    return count;
}
