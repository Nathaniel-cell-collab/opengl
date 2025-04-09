/*
** EPITECH PROJECT, 2025
** print_tab
** File description:
** display all the element of an array passed as parameter
*/

#include "my.h"

void print_tab(char **tab)
{
    while (*tab) {
        my_printf("%s\n", *tab);
        tab++;
    }
}
