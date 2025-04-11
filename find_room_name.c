/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** amazed
*/

#include "../include/amazed.h"

char *find_room_name(labyrinth_t *labyrinth, int wanted)
{
    int index = 0;

    for (room_t *room = labyrinth->rooms; room; room = room->next) {
        if (index == wanted)
            return room->name;
        index++;
    }
    return "";
}
