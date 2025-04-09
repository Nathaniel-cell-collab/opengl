/*
** EPITECH PROJECT, 2024
** my_put_float
** File description:
** jsp
*/
#include "my.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rounded_integer(char const *str, char const *str2, int *integer)
{
    if (str[0] == 57 && str2[0] == 48) {
        *integer = *integer + 1;
    }
}

char *rounded_number(char const *str, int *pinteger)
{
    char *str2 = my_strdup(str);
    int end = my_strlen(str) - 1;

    if (str[end] < 53) {
        str2[end] = '\0';
        return str2;
    }
    for (int i = end; i >= 0; i--) {
        if (str[i] >= 57) {
                str2[i] = 48;
        }
        if (str[i] != 57 && str[i + 1] > 52) {
                str2[i] = str2[i] + 1;
                str2[end] = '\0';
                return str2;
        }
    }
    str2[end] = '\0';
    rounded_integer(str, str2, pinteger);
    return str2;
}

int my_put_float(double fl, int n)
{
    int i = 0;
    int count = 0;
    char *str = malloc(sizeof(char) * (n + 2));
    int integer = (int)fl;
    char *str2 = NULL;

    if (fl < 0)
        fl = -fl;
    for (i = 0; i < n + 1; i++) {
        fl = (fl - (int)fl) * 10;
        str[i] = 48 + (int)fl;
    }
    str[i] = '\0';
    str2 = rounded_number(str, &integer);
    count += my_put_nbr(integer);
    count += my_putchar('.');
    count += my_putstr(str2);
    free(str);
    free(str2);
    return count;
}

int my_put_float_va(va_list list, ...)
{
    va_list flist;
    int count = 0;

    va_start(flist, list);
    count = my_put_float(va_arg(list, double), va_arg(flist, int));
    va_end(flist);
    return count;
}
