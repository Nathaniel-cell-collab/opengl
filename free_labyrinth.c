/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** free_labyrinth
*/

#include "amazed.h"

void free_labyrinth(labyrinth_t *labyrinth)
{
    room_t *free_room = NULL;

    if (labyrinth->nb_rbts <= 0)
        return;
    for (room_t *room = labyrinth->rooms; room; room = room->next) {
        if (!free_room) {
            free_room = room;
            continue;
        }
        my_free_array(free_room->links);
        my_free(free_room->name);
        my_free(free_room);
        free_room = room;
    }
    if (free_room) {
        my_free_array(free_room->links);
        my_free(free_room->name);
        my_free(free_room);
    }
    my_free(labyrinth);
}
