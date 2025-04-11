#include "bonus.h"

static float conver_to_NDC(float pos, float div) {
    return (pos / div) * 2.0f - 1.0f;
}

void init_room_bonus(sim_t *sim, elements_t *room)
{
    float x = room->x; 
    float y = room->y;
    float w = sim->screen.width;
    float h = sim->screen.height;
    float vertices[] = {
        conver_to_NDC(x, w),     conver_to_NDC(y, h),
        conver_to_NDC(x + 50, w), conver_to_NDC(y, h),
        conver_to_NDC(x + 50, w), conver_to_NDC(y + 50, h),
        conver_to_NDC(x, w),     conver_to_NDC(y + 50, h),
    };

    setupSquare(&(room->VAO), vertices, 32);
}

void create_rooms_map(sim_t *sim, labyrinth_t *labyrinth)
{
    int i = 0;
    room_t *saveptr = labyrinth->rooms;

    sim->map->rooms = calloc(sim->map->nb_room, sizeof(elements_t *));
    if (!(sim->map->rooms))
        return;
    for (i = 0; i < sim->map->nb_room; i++){
        sim->map->rooms[i] = calloc(1, sizeof(elements_t));
        if (!(sim->map->rooms[i])) {
            sim->map->rooms = NULL;
            return;
        }
        sim->map->rooms[i]->name = labyrinth->rooms->name;
        sim->map->rooms[i]->x = (labyrinth->rooms->x * 1820) / (labyrinth->nb_rooms * 10);
        sim->map->rooms[i]->y = (labyrinth->rooms->y * 980) / (labyrinth->nb_rooms * 10);
        init_room_bonus(sim, sim->map->rooms[i]);
        labyrinth->rooms = labyrinth->rooms->next;
    }
    labyrinth->rooms = saveptr;
    sim->map->rooms[i] = NULL;
}