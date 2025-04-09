/*
** EPITECH PROJECT, 2024
** my_put_adress
** File description:
** display the adress of a pointer
*/
#include "my.h"

int my_put_adress(long unsigned nbr)
{
    int i = 0;
    int count = 0;
    int j = 0;
    char *base = "0123456789abcdef";
    long unsigned tmp = nbr;
    int div = my_strlen(base);

    count += my_putstr("0x");
    for (i = 0; tmp > 0; i++) {
        tmp /= div;
    }
    for (i = i; i != 0; i--) {
        tmp = nbr;
        for (j = 0; j < i - 1; j++) {
            tmp /= div;
        }
        tmp = tmp % div;
        count += my_putchar(base[tmp]);
    }
    return count;
}

int my_put_adress_va(va_list list, ...)
{
    return my_put_adress(va_arg(list, long unsigned));
}
