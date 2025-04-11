/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell2-quentin-stephane.taranne-payet
** File description:
** is_in_str
*/

#include "amazed.h"

int is_in_str(char c, char *str)
{
    for (int a = 0; a < my_strlen(str); a++) {
        if (str[a] == c) {
            return 1;
        }
    }
    return 0;
}
