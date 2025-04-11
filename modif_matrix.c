/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** amazed
*/

#include "../include/amazed.h"

void modif_matrix(int **matrix, int nb_rooms, int index, int prev)
{
    if (prev == -1)
        matrix[index][index] = -2;
    if (prev != -1 && matrix[prev][prev] == -2)
        matrix[index][index] = 1;
    if (prev != -1 && matrix[prev][prev] != -2)
        matrix[index][index] = matrix[prev][prev] + 1;
    for (int i = nb_rooms; 0 <= i; i--) {
        if (i == index || i == prev)
            continue;
        if (matrix[index][i] == 1
            && (matrix[i][i] > matrix[index][index] + 1 || !matrix[i][i]))
            modif_matrix(matrix, nb_rooms, i, index);
    }
}

void init_diag(int **matrix, int nb_rooms)
{
    for (int i = 0; i < nb_rooms; i++)
        matrix[i][i] = 0;
}

int check_valid_matrix(int **matrix, labyrinth_t *labyrinth)
{
    int index_start = find_room_index(labyrinth, labyrinth->start_room->name);

    if (!matrix[index_start][index_start])
        return 84;
    my_putstr("#moves\n", 1);
    return 0;
}
