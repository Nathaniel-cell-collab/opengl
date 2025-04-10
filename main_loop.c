#include "bonus.h"

void main_loop(sim_t *sim)
{
    while(!glfwWindowShouldClose(sim->window))
    {
        clear_screen();
        manage_input(sim);
        display_sim(sim);
    }
}