/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include "amazed.h"
#include <stdlib.h>

int count_words(char const *str, char *separators)
{
    int i = 0;
    int compteur = 0;
    bool is_in_quotes = false;

    if (is_in_str(str[i], separators))
        compteur = compteur + 1;
    i = i + 1;
    while (str[i] != '\0') {
        if (str[i] == '"')
            is_in_quotes = !is_in_quotes;
        if (is_in_str(str[i], separators)
            && !is_in_str(str[i - 1], separators) && !is_in_quotes)
            compteur = compteur + 1;
        i = i + 1;
    }
    return compteur + !is_in_str(str[i - 1], separators);
}

int count_separators(char *str, int len_tot, int d)
{
    int compteur = 0;

    while (str[compteur] == '\0' && compteur + d < len_tot)
        compteur = compteur + 1;
    return compteur;
}

char *transform(char const *str, char *separators)
{
    int i = 0;
    char *strm = NULL;
    bool is_in_quotes = false;

    strm = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (!strm)
        return NULL;
    while (str[i] != 0) {
        if (str[i] == '"')
            is_in_quotes = !is_in_quotes;
        if (is_in_str(str[i], separators) && !is_in_quotes)
            strm[i] = '\0';
        else
            strm[i] = str[i];
        i = i + 1;
    }
    strm[i] = '\0';
    return strm;
}

char **my_str_to_word_array(char const *str, char separa[])
{
    char *strm = transform(str, separa);
    int len_tot = my_strlen(str);
    char **array = malloc(sizeof(char *) * (count_words(str, separa) + 1));
    int d = 0;
    int i = 0;
    int separators = count_separators(strm, len_tot, d);

    if (!array)
        return NULL;
    while (d < len_tot - separators) {
        array[i] = my_strdup(strm + d + separators);
        d += my_strlen(array[i]);
        separators = separators + count_separators(strm + d + separators,
        len_tot, d + separators);
        i = i + 1;
    }
    my_free(strm);
    array[i] = NULL;
    return array;
}
