/*
** EPITECH PROJECT, 2024
** is_hexlower_va
** File description:
** jsp
*/
#include "my.h"

int is_hexlower_va(va_list list, ...)
{
    int count = 0;

    count += my_putnbr_base(va_arg(list, unsigned), "0123456789abcdef");
    return count;
}
