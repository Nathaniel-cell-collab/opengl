/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** jj
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *my_strndup(char const *src, int start, int end)
{
    int i = 0;
    char *new_string = malloc(sizeof(char) * end + 1);
    int j = 0;

    for (i = start; src[i] != '\0' && i < start + end; i++) {
        new_string[j] = src[i];
        j++;
    }
    new_string[j] = '\0';
    return new_string;
}
