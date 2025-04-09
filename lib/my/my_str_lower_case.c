/*
** EPITECH PROJECT, 2024
** my_str_lower_case
** File description:
** put all the char of a  string in lower case
*/

int is_upper(char c)
{
    if (c >= 65 && c <= 90)
        return 1;
    return 0;
}

char *my_str_lower_case(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_upper(str[i]) == 1)
            str[i] = str[i] + 32;
    }
    return str;
}
