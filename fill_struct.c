/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** main
*/

#include "amazed.h"

int init_labyrinth(labyrinth_t *labyrinth)
{
    labyrinth->end_room = NULL;
    labyrinth->nb_rbts = 0;
    labyrinth->nb_rooms = 0;
    labyrinth->rooms = NULL;
    labyrinth->robots = NULL;
    labyrinth->start_room = NULL;
    return 0;
}

void print_nb_robots(labyrinth_t *lab)
{
    my_putstr("#number_of_robots\n", 1);
    my_put_nbr(lab->nb_rbts);
    my_putstr("\n", 1);
    my_putstr("#rooms\n", 1);
}

int get_nbr_of_robots(labyrinth_t *lab, size_t *n, char *line)
{
    int res = 0;

    while (res != -1) {
        res = getline(&line, n, stdin);
        if (res == -1)
            return 84;
        if (*line == '#')
            continue;
        if (line[my_strlen(line) - 1] == '\n')
            line[my_strlen(line) - 1] = '\0';
        if (*line == 0 || !is_num(line))
            return 84;
        lab->nb_rbts = my_getnbr(line);
        break;
    }
    print_nb_robots(lab);
    my_free(line);
    return 0;
}

int fill_struct(labyrinth_t *labyrinth)
{
    char *line = NULL;
    size_t n = 0;
    int res = 0;
    int test = 0;

    if (init_labyrinth(labyrinth) || get_nbr_of_robots(labyrinth, &n, line))
        return 84;
    for (int i = 0; res != -1; i++) {
        res = getline(&line, &n, stdin);
        if (res == -1)
            break;
        if (line[my_strlen(line) - 1] == '\n')
            line[my_strlen(line) - 1] = '\0';
        test = pattern_matching(line, labyrinth);
        if (test == 84 || test == 2)
            break;
    }
    my_free(line);
    return labyrinth->end_room && labyrinth->start_room &&
        labyrinth->nb_rbts > 0 && (test == 1 || test == 2) ? test : 84;
}
