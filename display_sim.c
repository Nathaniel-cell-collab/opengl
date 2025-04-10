/*
** EPITECH PROJECT, 2025
** opengl
** File description:
** display_sim
*/

#include "bonus.h"

void clear_screen(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawAllRooms(sim_t *sim)
{
    for (int i = 0; i < sim->map->nb_room; i++) {
        glUseProgram(sim->shaderProgam);
        glBindVertexArray(sim->map->rooms[i]->VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}

void display_sim(sim_t *sim)
{
    drawAllRooms(sim);
    glfwSwapBuffers(sim->window);
}