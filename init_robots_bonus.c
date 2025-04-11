#include "bonus.h"

static float conver_to_NDC(float pos, float div) {
    return (pos / div) * 2.0f - 1.0f;
}

void init_robots_bonus(sim_t *sim, elements_t *robot)
{
    int size = 30;
    float w = sim->screen.width;
    float h = sim->screen.height;
    float tri_height = size * 0.866f;
    float x1 = robot->x;
    float y1 = robot->y + (2.0f / 3.0f) * tri_height;
    float x2 = robot->x - (size / 2.0f);
    float y2 = robot->y - (1.0f / 3.0f) * tri_height;
    float x3 = robot->x + (size / 2.0f);
    float y3 = y2;
    float vertices[] = {
        conver_to_NDC(x1, w), conver_to_NDC(y1, h),
        conver_to_NDC(x2, w), conver_to_NDC(y2, h),
        conver_to_NDC(x3, w), conver_to_NDC(y3, h),
    };

    setupTriangle(&(robot->VAO), vertices, 24);
}

void create_robots_map(sim_t *sim, labyrinth_t *labyrinth)
{
    int i = 0;

    sim->map->robots = calloc(sim->map->nb_robot, sizeof(elements_t *));
    if (!(sim->map->robots))
        return;
    for (i = 0; i < sim->map->nb_robot; i++){
        sim->map->robots[i] = calloc(1, sizeof(elements_t));
        if (!(sim->map->robots[i])) {
            sim->map->robots = NULL;
            return;
        }
        sim->map->robots[i]->id = labyrinth->robots[i].id;
        sim->map->robots[i]->x = (labyrinth->start_room->x * 1820) / (labyrinth->nb_rooms * 10) + 24;
        sim->map->robots[i]->y = (labyrinth->start_room->y * 980) / (labyrinth->nb_rooms * 10) + 22;
        init_robots_bonus(sim, sim->map->robots[i]);
    }
    sim->map->robots[i] = NULL;
}