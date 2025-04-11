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
#include "amazed.h"

typedef struct elements_s {
    char *name;
    float x;
    float y;
    unsigned int VAO;
    int id;
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
    unsigned int shaderRobots;
    map_t *map;
    screen_prop_t screen;
    int update;
} sim_t;

void init_robots_bonus(sim_t *sim, elements_t *robot);
void update_robot_bonus(sim_t *sim,labyrinth_t *labyrinth);
unsigned int createShaderRobots(void);
void create_robots_map(sim_t *sim, labyrinth_t *labyrinth);
void setupTriangle(unsigned int* VAO, float* vertices, size_t size);
int use_robots(int **matrix, labyrinth_t *labyrinth, int index_end, sim_t *sim);
void create_rooms_map(sim_t *sim, labyrinth_t *labyrinth);
sim_t *init_sim(sim_t *sim, labyrinth_t *labyrinth);
void init_context(sim_t *sim);
void manage_input(sim_t *sim);
void clear_screen(void);
void display_sim(sim_t *sim);
void main_loop(sim_t *sim, labyrinth_t *labyrinth, int **matrix);
unsigned int createShaderProgram(void);
void setupSquare(unsigned int* VAO, float *vertices, size_t size);
int apply_matrix(int **matrix, labyrinth_t *labyrinth, sim_t *sim);
#endif /* !BONUS_H_ */
