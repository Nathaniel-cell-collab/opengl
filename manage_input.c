#include "bonus.h"

void processInput(sim_t *sim)
{
    if (glfwGetKey(sim->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(sim->window, true);
    if (glfwGetKey(sim->window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        glClearColor(0.0f, 0.0f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void manage_input(sim_t *sim)
{
    processInput(sim);
    glfwPollEvents();
}