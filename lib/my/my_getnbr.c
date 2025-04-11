/*
** EPITECH PROJECT, 2024
** my_get_nbr
** File description:
** lalaa
*/

#include "amazed.h"

int get_sign(char const *str)
{
    int i = 0;
    int mo = 1;

    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-') {
            mo = mo * -1;
        }
        i = i + 1;
    }
    return mo;
}

int count(char const *str)
{
    int i = 0;
    int mo = 0;

    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-' || str[i] == '+') {
            mo = mo + 1;
        }
        i = i + 1;
    }
    return mo;
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int mo = get_sign(str);
    int y = 0;
    int counter = count(str);
    int i = counter;

    while (str[i] >= '0' && str[i] <= '9') {
        nbr = nbr * 10 + (str[i] - '0');
        i = i + 1;
        y = 1;
    }
    if (str[i] < '0' || (str[i] > '9' && y == 1))
        return nbr * mo;
    else if (str[i] < '0' || (str[i] > '9' && y == 0))
        return 0;
    i = i + 1;
    return 0;
}
