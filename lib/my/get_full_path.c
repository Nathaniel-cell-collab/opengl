/*
** EPITECH PROJECT, 2025
** get_full_path
** File description:
** get the full_path of a command
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char *get_full_path(char *dir, char *exec)
{
    char *full_path = NULL;

    if (!dir || !exec)
        return NULL;
    full_path = malloc(sizeof(char) * (my_strlen(dir) +
    my_strlen(exec) + 2));
    if (!full_path)
        return NULL;
    full_path = my_strcpy(full_path, dir);
    my_strncat(full_path, "/", 0);
    my_strncat(full_path, exec, 0);
    return full_path;
}
