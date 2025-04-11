/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** print_info
*/

#include "amazed.h"

void print_rooms(room_t *current)
{
    if (!current)
        return;
    my_putstr(current->name, 1);
    my_putstr(" ", 1);
    my_put_nbr(current->x);
    my_putstr(" ", 1);
    my_put_nbr(current->y);
    my_putstr("\n", 1);
}
