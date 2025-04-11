/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** count_occur
*/

#include "amazed.h"

int count_occur(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            count++;
    return count;
}
