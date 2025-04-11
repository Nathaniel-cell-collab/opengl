/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** gener_matrix
*/

#include "../include/amazed.h"

int alloc_lines(int **matrix, labyrinth_t *labyrinth)
{
    for (int i = 0; i < labyrinth->nb_rooms; i++) {
        matrix[i] = malloc(sizeof(int) * labyrinth->nb_rooms);
        if (!matrix[i])
            return 84;
    }
    matrix[labyrinth->nb_rooms] = NULL;
    return 0;
}

int find_room_index(labyrinth_t *labyrinth, char *room_name)
{
    int index = 0;

    for (room_t *room = labyrinth->rooms; room; room = room->next) {
        if (my_strcmp(room->name, room_name))
            return index;
        index++;
    }
    return 0;
}

int **gener_matrix(labyrinth_t *labyrinth)
{
    int **matrix = malloc(sizeof(int *) * (labyrinth->nb_rooms + 1));
    int room1_index = 0;
    int room2_index = 0;

    if (!matrix)
        return NULL;
    if (alloc_lines(matrix, labyrinth) == 84)
        return NULL;
    for (int i = 0; i < labyrinth->nb_rooms; i++)
        for (int j = 0; j < labyrinth->nb_rooms; j++)
            matrix[i][j] = 0;
    for (room_t *room = labyrinth->rooms; room; room = room->next) {
        room1_index = find_room_index(labyrinth, room->name);
        for (int i = 0; room->links[i]; i++) {
            room2_index = find_room_index(labyrinth, room->links[i]);
            matrix[room1_index][room2_index] = 1;
            matrix[room2_index][room1_index] = 1;
        }
    }
    return matrix;
}
