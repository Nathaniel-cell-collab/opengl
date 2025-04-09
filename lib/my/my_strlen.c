/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** jsp
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}
