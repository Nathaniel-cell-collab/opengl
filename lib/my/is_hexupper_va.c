/*
** EPITECH PROJECT, 2024
** ishexupper_va
** File description:
** jsp
*/
#include "my.h"

int is_hexupper_va(va_list list, ...)
{
    int count = 0;

    count += my_putnbr_base(va_arg(list, unsigned), "0123456789ABCDEF");
    return count;
}
