/*
** EPITECH PROJECT, 2024
** multiple_conditions
** File description:
** momo
*/

#include "my.h"

void digit_flag_conditions(char const *format, int *pp, int *pn, int count)
{
    if (format[*pp] == '.' && char_isdigit(format[*pp + 1]) == 1) {
            *pn = my_getnbr(format, *pp);
            *pp = *pp + len_nbr(*pn) + 1;
    }
    if (format[*pp] == 'n') {
        *pn = count;
    }
}
