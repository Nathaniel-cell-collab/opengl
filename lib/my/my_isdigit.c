/*
** EPITECH PROJECT, 2025
** my_isdigit
** File description:
** return 1 if a char is digit
*/

int my_isdigit(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    return 0;
}
