/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** fill_room
*/

#include "amazed.h"

void init_room(room_t *room)
{
    room->index = 0;
    room->links = NULL;
    room->name = NULL;
    room->next = NULL;
    room->x = 0;
    room->y = 0;
}

int verif_error_room(labyrinth_t *labyrinth, room_t *new_room, char **info)
{
    new_room->name = my_strdup(info[0]);
    if (!new_room->name || !is_num(info[1]) || !is_num(info[2]))
        return 84;
    new_room->x = my_getnbr(info[1]);
    new_room->y = my_getnbr(info[2]);
    for (room_t *room = labyrinth->rooms; room; room = room->next) {
        if (my_strcmp(new_room->name, room->name)) {
            my_free(new_room->name);
            my_free(new_room);
            return 84;
        }
        if (new_room->x == room->x && new_room->y == room->y) {
            my_free(new_room->name);
            my_free(new_room);
            return 84;
        }
    }
    return 0;
}

int fill_room(labyrinth_t *labyrinth, char *line)
{
    room_t *room = malloc(sizeof(room_t));
    char **info = my_str_to_word_array(line, " ");

    if (!info || !room || my_array_len(info) != 3)
        return 84;
    init_room(room);
    if (verif_error_room(labyrinth, room, info) == 84)
        return 84;
    room->links = malloc(sizeof(char *) * 1);
    if (!room->links)
        return 84;
    room->index = labyrinth->nb_rooms;
    *room->links = NULL;
    room->next = labyrinth->rooms;
    labyrinth->rooms = room;
    labyrinth->nb_rooms += 1;
    print_rooms(labyrinth->rooms);
    my_free_array(info);
    return 0;
}

int add_room(labyrinth_t *labyrinth, char *line,
    int *trigger_start, int *trigger_end)
{
    for (int i = 0; line[i]; i++)
        line[i] = line[i] == '#' ? '\0' : line[i];
    if (count_words(line, " \n\t") == 3) {
        if (fill_room(labyrinth, line) == 84)
            return 84;
        if (*trigger_start == 1) {
            labyrinth->start_room = labyrinth->rooms;
            *trigger_start = 2;
        }
        if (*trigger_end == 1) {
            labyrinth->end_room = labyrinth->rooms;
            *trigger_end = 2;
        }
    } else
        return 84;
    return 0;
}
