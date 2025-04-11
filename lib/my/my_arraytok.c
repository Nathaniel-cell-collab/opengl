/*
** EPITECH PROJECT, 2025
** B-PSU-200-RUN-2-1-minishell2-quentin-stephane.taranne-payet
** File description:
** my_arraytok
*/

#include "amazed.h"

char **my_arraytok(char **list, char *cmp)
{
    char *tab[256] = {0};
    int y = 0;
    static int i = 0;

    if (!(*list) || !(*(list + i)) || !cmp) {
        i = 0;
        return NULL;
    }
    list = list + i;
    for (; list[y]; i++) {
        if (my_strcmp(list[y], cmp)) {
            i++;
            tab[y] = NULL;
            break;
        }
        tab[y] = list[y];
        y++;
    }
    return my_listdup(tab);
}
