#include "bonus.h"

void processInput(sim_t *sim)
{
    if (glfwGetKey(sim->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(sim->window, true);
}

void manage_input(sim_t *sim)
{
    processInput(sim);
    glfwPollEvents();
}