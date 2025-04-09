/*
** EPITECH PROJECT, 2024
** putchar
** File description:
** p
*/

#include <unistd.h>
#include "my.h"

int my_putchar(int c)
{
    int i = 0;

    i = write(1, &c, 1);
    return i;
}

int my_putchar_va(va_list list, ...)
{
    return my_putchar(va_arg(list, int));
}
