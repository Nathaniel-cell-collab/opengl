/*
** EPITECH PROJECT, 2025
** opengl
** File description:
** bonus
*/

#ifndef BONUS_H_
    #define BONUS_H_
#include "glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my.h"


typedef struct sim_s {
    GLFWwindow *window;
    unsigned int shaderProgam;
    unsigned int VAO;
} sim_t;

void main_loop(sim_t *sim);
void processInput(GLFWwindow *window);
unsigned int createShaderProgram(void);
void setupSquare(unsigned int* VAO, float *vertices, size_t size);
#endif /* !BONUS_H_ */
