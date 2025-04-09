/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** jj
*/
#include "my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *new_string = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (i = 0; src[i] != '\0'; i++) {
        new_string[i] = src[i];
    }
    new_string[i] = '\0';
    return new_string;
}
