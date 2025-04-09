/*
** EPITECH PROJECT, 2024
** isocta_va.c
** File description:
** jsp
*/
#include "my.h"

int is_octal_va(va_list list, ...)
{
    int count = 0;

    count += my_putnbr_base(va_arg(list, unsigned), "01234567");
    return count;
}
