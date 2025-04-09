/*
** EPITECH PROJECT, 2025
** my_tab_to_space
** File description:
** change a character of a string in another character
*/

char *my_str_change_char(char *str, char to_change, char for_change)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_change)
            str[i] = for_change;
    }
    return str;
}
