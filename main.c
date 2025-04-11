/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** main
*/

#include "../include/amazed.h"
#include "bonus.h"
#include <stdio.h>


int main(void)
{
    labyrinth_t *labyrinth = malloc(sizeof(labyrinth_t));
    sim_t *sim = calloc(1, sizeof(sim_t));
    int **matrix = NULL;

    if (!labyrinth)
        return 84;
    if (fill_struct(labyrinth) == 84) {
        free_labyrinth(labyrinth);
        return 84;
    }
    init_context(sim);
    sim = init_sim(sim, labyrinth);
    matrix = gener_matrix(labyrinth);
    if (!matrix) {
        free_labyrinth(labyrinth);
        return 84;
    }
    main_loop(sim, labyrinth, matrix);
    free_labyrinth(labyrinth);
    my_free_int_array(matrix);
    return 0;
}
