/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** main
*/

#include "amazed.h"

int triggers_start_end(char *line, int *start, int *end)
{
    if (my_strcmp(line + 2, "start")) {
        if (*start == 2)
            return 84;
        *start = 1;
        my_putstr("##start\n", 1);
    }
    if (my_strcmp(line + 2, "end")) {
        if (*end == 2)
            return 84;
        *end = 1;
        my_putstr("##end\n", 1);
    }
    return *start || *end ? 0 : 84;
}

int new_link(labyrinth_t *labyrinth, char *line, int *mode)
{
    if (*mode == 0) {
        if (!labyrinth->start_room || !labyrinth->end_room)
            return 84;
        my_putstr("#tunnels\n", 1);
    }
    *mode = 1;
    if (add_link(labyrinth, line) == 84)
        return 2;
    my_putstr(line, 1);
    my_putstr("\n", 1);
    return 1;
}

int pattern_matching(char *line, labyrinth_t *labyrinth)
{
    static int trigger_start = 0;
    static int trigger_end = 0;
    static int mode = 0;

    if (!line || !*line || !labyrinth)
        return 84;
    if (line[0] == '#' && line[1] && line[1] != '#')
        return 0;
    if (count_occur(line, '-') == 1)
        return new_link(labyrinth, line, &mode);
    if (mode == 0) {
        if (line[0] == '#' && line[1] && line[1] == '#')
            return triggers_start_end(line, &trigger_start, &trigger_end);
        return add_room(labyrinth, line, &trigger_start, &trigger_end);
    }
    return mode == 1 ? 2 : 84;
}
