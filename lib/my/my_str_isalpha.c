/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_str_isalpha
*/

#include "amazed.h"

int is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int is_alphanum(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
    (c >= '0' && c <= '9') || (c == '_'))
        return 1;
    return 0;
}

int my_str_isalpaha(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!is_alphanum(str[i]))
            return 0;
    }
    return 1;
}
