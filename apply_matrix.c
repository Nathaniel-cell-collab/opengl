/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** amazed
*/

#include "bonus.h"

char tunel_unused(labyrinth_t *labyrinth, int index, int i)
{
    int index_end = find_room_index(labyrinth, labyrinth->end_room->name);

    if (index_end != i)
        return 1;
    for (int j = 0; j < labyrinth->nb_rbts; j++) {
        if (j == index)
            continue;
        if (labyrinth->robots[j].pos == index_end &&
            labyrinth->robots[j].tick == labyrinth->robots[index].tick
            && labyrinth->robots[j].prev_pos ==
            labyrinth->robots[index].pos)
            return 0;
    }
    return 1;
}

int change_room(int **matrix, int index, labyrinth_t *labyrinth, int moved)
{
    robots_t *temp = &labyrinth->robots[index];

    for (int i = 0; i < labyrinth->nb_rooms; i++) {
        if (i == temp->pos || i == temp->prev_pos)
            continue;
        if (matrix[temp->pos][i] == 1 && matrix[i][i] < temp->room_value
            && matrix[i][i] != -1
            && tunel_unused(labyrinth, index, i)) {
            moved += (moved) ? my_putstr(" ", 1) : 0;
            return update_robot(matrix, i, temp, labyrinth);
        }
    }
    return 0;
}

char is_over(labyrinth_t *labyrinth, int index_end)
{
    int i = 0;

    for (; i < labyrinth->nb_rbts &&
        labyrinth->robots[i].pos == index_end; i++);
    return i == labyrinth->nb_rbts;
}

int apply_matrix(int **matrix, labyrinth_t *labyrinth, sim_t *sim)
{
    int index = find_room_index(labyrinth, labyrinth->end_room->name);

    init_diag(matrix, labyrinth->nb_rooms);
    modif_matrix(matrix, labyrinth->nb_rooms - 1, index, -1);
    if (check_valid_matrix(matrix, labyrinth)
        || use_robots(matrix, labyrinth, index, sim)) {
        free_labyrinth(labyrinth);
        my_free_int_array(matrix);
        return 84;
    }
    return 0;
}
