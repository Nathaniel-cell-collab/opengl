/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** jsp
*/
#include "my.h"

int my_put_unsigned(unsigned int nb)
{
    int i = 0;
    int j = 1;

    while ((nb / j) > 9) {
        j *= 10;
    }
    while (j > 0) {
        i += my_putchar('0' + (nb / j) % 10);
        j /= 10;
    }
    return i;
}

int my_put_unsigned_va(va_list list, ...)
{
    return my_put_unsigned(va_arg(list, unsigned int));
}
