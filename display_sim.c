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

void drawAllRooms(sim_t *sim, int colorLoc)
{
    glUniform4f(colorLoc, 1.0f, 0.0f, 0.0f, 1.0f);
    for (int i = 0; i < sim->map->nb_room; i++) {
        glBindVertexArray(sim->map->rooms[i]->VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}

void drawAllRobots(sim_t *sim, int colorLoc)
{
    glUniform4f(colorLoc, 0.0f, 1.0f, 0.0f, 1.0f);
    for (int i = 0; i < sim->map->nb_robot; i++) {
        glBindVertexArray(sim->map->robots[i]->VAO);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    }
}

void display_sim(sim_t *sim)
{
    int colorLoc = 0;
    glUseProgram(sim->shaderProgam);
    colorLoc = glGetUniformLocation(sim->shaderProgam, "uColor");
    drawAllRooms(sim, colorLoc);
    if ((sim->map->robots))
        drawAllRobots(sim, colorLoc);
    glfwSwapBuffers(sim->window);
}