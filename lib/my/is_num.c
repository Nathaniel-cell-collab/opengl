/*
** EPITECH PROJECT, 2025
** lib
** File description:
** is_num
*/

#include "amazed.h"

int is_num(char *line)
{
    for (int i = 0; line[i]; ++i)
        if (!(line[i] >= '0' && line[i] <= '9'))
            return 0;
    return 1;
}
