/*
** EPITECH PROJECT, 2018
** my_is_prime.c
** File description:
** CPool_Day05_2018
*/

int my_is_prime(int nb)
{
    int i = 1;

    for (int n = 2; n <= nb; n++)
        i = (nb%n == 0) ? i + 1 : i;
    if (i == 2)
        return (1);
    return (0);
}