#include "bonus.h"

void main_loop(sim_t *sim)
{
    while(!glfwWindowShouldClose(sim->window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        processInput(sim->window);
        glUseProgram(sim->shaderProgam);
        glBindVertexArray(sim->VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(sim->window);
        glfwPollEvents();
    }
}