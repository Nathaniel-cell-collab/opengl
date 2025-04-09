/*
** EPITECH PROJECT, 2024
** len_nbr
** File description:
** get how many digit in a number
*/
int len_nbr(int nb)
{
    int i = 1;
    int j = 1;

    while ((nb / j) > 9) {
        j *= 10;
        i++;
    }
    return i;
}
