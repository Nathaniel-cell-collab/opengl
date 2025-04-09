/*
** EPITECH PROJECT, 2024
** my_put_nbr_base
** File description:
** jsp
*/
#include "my.h"

static int if_zero(int nbr)
{
    int count = 0;

    if (nbr == 0) {
        count += my_putchar('0');
    }
    return count;
}

int my_putnbr_base(unsigned nbr, char const *base)
{
    int i = 0;
    int count = 0;
    int j = 0;
    unsigned tmp = nbr;
    int div = my_strlen(base);

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
    count += if_zero(nbr);
    return count;
}
