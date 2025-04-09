/*
** EPITECH PROJECT, 2024
** my_str_to_word
** File description:
** jj
*/

#include <stdlib.h>
#include "my.h"

int my_ischar(char c, char sep)
{
    if (c == sep || c == '\0')
        return 0;
    return 1;
}

int nb_word(char const *str, char sep)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i + 1] == '\0') {
            count++;
            return count;
        }
        if (my_ischar(str[i], sep) == 0 && my_ischar(str[i + 1], sep) == 1) {
            count++;
        }
    }
    return count;
}

int alloc_str(char const *str, int n, char sep)
{
    int count = 0;

    for (int i = n; my_ischar(str[i], sep) == 1; i++) {
        count++;
    }
    return count;
}

char *copy_string(int i, char const *str, char sep, int *k)
{
    int count = alloc_str(str, i, sep);
    char *cpy_str = my_strndup(str, i, count);

    if (!cpy_str)
        return NULL;
    if (cpy_str[0] == 0){
        free(cpy_str);
        return NULL;
    }
    if (i == 0 || (my_ischar(str[i], sep) == 1
    && my_ischar(str[i - 1], sep) == 0)) {
        (*k)++;
        return cpy_str;
    }
    free(cpy_str);
    return NULL;
}

char **my_str_to_word_array(char const *str, char sep)
{
    int len = nb_word(str, sep);
    char **tab = malloc(sizeof(char *) * (len + 1));
    int k = 0;
    int i = 0;

    if (tab == NULL)
        return NULL;
    for (i = 0; str[i] != '\0'; i++) {
            tab[k] = copy_string(i, str, sep, &k);
    }
    tab[k] = NULL;
    return tab;
}
