/*
** EPITECH PROJECT, 2025
** B-CPE-200-RUN-2-1-amazed-nathaniel.leperlier
** File description:
** main
*/

#include "amazed.h"

int add_link(labyrinth_t *labyrinth, char *line)
{
    char **tab = my_str_to_word_array(line, "-");
    room_t *room = labyrinth->rooms;
    int verif = 0;

    if (!tab || !*tab || my_array_len(tab) != 2)
        return 84;
    for (int i = 0; i < labyrinth->nb_rooms; i++) {
        if (my_strcmp(room->name, *tab)) {
            room->links = my_push_tab(room->links, tab[1]);
            verif += 1;
        }
        if (my_strcmp(room->name, tab[1])) {
            room->links = my_push_tab(room->links, tab[0]);
            verif += 1;
        }
        room = room->next;
    }
    my_free_array(tab);
    return verif == 2 ? 0 : 84;
}
