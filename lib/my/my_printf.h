/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mfm
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_
    #include <stdarg.h>
    #include <unistd.h>
    #include "my.h"
struct flags {
    char flag;
    int (*function)(va_list, ...);
};

const struct flags FLAGS_FUNCS[] = {
    {'c', &my_putchar_va},
    {'s', &my_putstr_va},
    {'d', &my_put_nbr_va},
    {'i', &my_put_nbr_va},
    {'f', &my_put_float_va},
    {'b', &is_binary_va},
    {'o', &is_octal_va},
    {'x', &is_hexlower_va},
    {'X', &is_hexupper_va},
    {'u', &my_put_unsigned_va},
    {'p', &my_put_adress_va},
    {0, NULL}
};

#endif
