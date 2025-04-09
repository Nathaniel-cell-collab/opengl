/*
** EPITECH PROJECT, 2024
** my_get_number
** File description:
** get a number in a string
*/

#include <limits.h>
#include "my.h"

int char_isdigit(char a)
{
    if (a >= 48 && a <= 57){
        return 1;
    }
    return 0;
}

int skip(char const *str, int p)
{
    while (str[p] != '\0') {
        if (str[p] == '-' && char_isdigit(str[p + 1]) == 1) {
            return p;
        }
        if (char_isdigit(str[p]) == 1) {
            return p;
        }
        p++;
    }
    return p;
}

int write_nbr(int p, char const *str)
{
    int nbr = 0;
    int sign = 1;

    if (str[p] == '-'){
        sign = -1;
        p++;
    }
    while (char_isdigit(str[p]) == 1){
        nbr = nbr * 10 + (str[p] - '0');
        p += 1;
    }
    nbr = nbr *sign;
    if (nbr < 0)
        return -1;
    return nbr;
}

int my_getnbr(char const *str, int p)
{
    int my_nbr = 0;

    p = skip(str, p);
    if (p == my_strlen(str))
        return -1;
    my_nbr = write_nbr(p, str);
    return my_nbr;
}
