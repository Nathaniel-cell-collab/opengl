#include "bonus.h"

int getRobotsPosx(labyrinth_t *labyrinth, int wanted, char pos)
{
    int index = 0;

    for (room_t *room = labyrinth->rooms; room; room = room->next) {
        if (index == wanted && pos == 'x')
            return (room->x * 1820) / (labyrinth->nb_rooms * 10) + 24;;
        if (index == wanted && pos == 'y')
            return (room->y * 980) / (labyrinth->nb_rooms * 10) + 22;
        index++;
    }
    return 0;
}

void update_robot_bonus(sim_t *sim,labyrinth_t *labyrinth)
{
    for (int i = 0; i < labyrinth->nb_rbts; i++) {
        sim->map->robots[i]->x = getRobotsPosx(labyrinth, labyrinth->robots[i].pos, 'x');
        sim->map->robots[i]->y = getRobotsPosx(labyrinth, labyrinth->robots[i].pos, 'y');
        init_robots_bonus(sim, sim->map->robots[i]);
    }
}