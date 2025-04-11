#include "bonus.h"

void main_loop(sim_t *sim, labyrinth_t *labyrinth, int **matrix)
{
    while(!glfwWindowShouldClose(sim->window))
    {
        clear_screen();
        manage_input(sim);
        display_sim(sim);
        apply_matrix(matrix, labyrinth, sim);
    }
}