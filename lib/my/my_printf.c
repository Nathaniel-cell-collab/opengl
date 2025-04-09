/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** ff
*/

#include <stdio.h>
#include "my_printf.h"

int pass_flag(char const *format, int i)
{
    char *flag = "uiofdsxXcb.";

    for (int j = 0; flag[j]; j++) {
        if (format[i + 1] == flag[j]) {
            return 1;
        }
    }
    return 0;
}

int mapping_flags(char const *format, va_list list, int *pi, int count)
{
    int n = 6;
    int p = *pi + 1;

    digit_flag_conditions(format, &p, &n, count);
    for (int j = 0; FLAGS_FUNCS[j].flag; j++) {
        if (format[p] == FLAGS_FUNCS[j].flag) {
            *pi = p + 1;
            return FLAGS_FUNCS[j].function(list, n);
        }
    }
    if (format[p] == '%') {
        *pi = p + 1;
        return my_putchar('%');
    }
    return 0;
}

int my_printf(char const *format, ...)
{
    va_list list;
    int count = 0;
    int i = 0;

    va_start(list, format);
    while (i < my_strlen(format)) {
        if (format[i] == '%') {
            count += mapping_flags(format, list, &i, count);
        }
        if (i >= my_strlen(format))
            return 0;
        if ((format[i] == '%' && pass_flag(format, i) == 0)
                                        || format[i] != '%') {
            count += my_putchar(format[i]);
            i++;
        }
    }
    va_end(list);
    return count;
}
