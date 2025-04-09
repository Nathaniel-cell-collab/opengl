/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** jsp
*/
#include "my.h"

int my_putstr(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return i;
}

int my_putstr_va(va_list list, ...)
{
    return my_putstr(va_arg(list, char *));
}
