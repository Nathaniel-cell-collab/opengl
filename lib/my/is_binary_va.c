/*
** EPITECH PROJECT, 2024
** isbinary_va
** File description:
** jsp
*/
#include "my.h"

int is_binary_va(va_list list, ...)
{
    int count = 0;

    count += my_putnbr_base(va_arg(list, unsigned), "01");
    return count;
}
