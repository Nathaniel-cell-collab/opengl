/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** my_free
*/

#include "amazed.h"
void my_free(void *pointer)
{
    if (pointer)
        free(pointer);
}
