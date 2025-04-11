/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_putstr
*/

#include "amazed.h"

int my_putstr(char *str, int out)
{
    return write(out, str, my_strlen(str));
}
