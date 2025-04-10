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

typedef struct elements_s {
    char *name;
    float x;
    float y;
    unsigned int VAO;
} elements_t;

typedef struct map_s {
    int nb_room;
    elements_t **rooms;
    int nb_robot;
    elements_t **robots;
} map_t;

typedef struct screen_properties_s {
    int height;
    int width;
} screen_prop_t;

typedef struct sim_s {
    GLFWwindow *window;
    unsigned int shaderProgam;
    map_t *map;
    screen_prop_t screen;
} sim_t;

void manage_input(sim_t *sim);
void clear_screen(void);
void display_sim(sim_t *sim);
void main_loop(sim_t *sim);
unsigned int createShaderProgram(void);
void setupSquare(unsigned int* VAO, float *vertices, size_t size);
#endif /* !BONUS_H_ */
