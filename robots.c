/*
** EPITECH PROJECT, 2025
** amazed
** File description:
** amazed
*/

#include "bonus.h"

robots_t *init_robots(int index_start, int nb_rbts, int value_start)
{
    robots_t *robots = malloc(sizeof(robots_t) * nb_rbts);

    if (!robots)
        return NULL;
    for (int i = 0; i < nb_rbts; i++) {
        robots[i].id = i + 1;
        robots[i].pos = index_start;
        robots[i].room_value = value_start;
        robots[i].prev_pos = index_start;
        robots[i].tick = 0;
    }
    return robots;
}

int update_robot(int **matrix, int i, robots_t *robot, labyrinth_t *labyrinth)
{
    matrix[robot->pos][robot->pos] = robot->room_value;
    robot->prev_pos = robot->pos;
    robot->pos = i;
    robot->room_value = matrix[i][i];
    matrix[i][i] = -1;
    my_putstr("P", 1);
    my_put_nbr(robot->id);
    my_putstr("->", 1);
    my_putstr(find_room_name(labyrinth, i), 1);
    return 1;
}

static int move_robots(int **matrix, labyrinth_t *labyrinth, int index_end)
{
    int moved = 0;

    for (int i = 0; i < labyrinth->nb_rbts; i++)
        if (labyrinth->robots[i].pos != index_end) {
            moved += change_room(matrix, i, labyrinth, moved);
            matrix[index_end][index_end] = 0;
        }
    for (int i = 0; i < labyrinth->nb_rbts; i++)
        if (labyrinth->robots[i].pos != index_end)
            labyrinth->robots[i].tick++;
    my_putstr("\n", 1);
    return is_over(labyrinth, index_end);
}

bool detectClick(GLFWwindow* window)
{
    static bool previousPressed = false;
    bool currentPressed = glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS;
    bool clicked = currentPressed && !previousPressed;

    previousPressed = currentPressed;
    return clicked;
}

int use_robots(int **matrix, labyrinth_t *labyrinth, int index_end, sim_t *sim)
{
    int index_start = find_room_index(labyrinth, labyrinth->start_room->name);
    int res = 0;
    labyrinth->robots = init_robots(index_start, labyrinth->nb_rbts,
                                    matrix[index_start][index_start]);
    if (!labyrinth->robots)
        return 84;
    create_robots_map(sim, labyrinth);
    while (!res) {
        if (detectClick(sim->window)) {
            res = move_robots(matrix, labyrinth, index_end);
        }        
        update_robot_bonus(sim, labyrinth);
        clear_screen();
        manage_input(sim);
        display_sim(sim);
    }
    update_robot_bonus(sim, labyrinth);
    clear_screen();
    manage_input(sim);
    display_sim(sim);
    my_free(labyrinth->robots);
    return 0;
}
