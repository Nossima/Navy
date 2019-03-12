/*
** EPITECH PROJECT, 2018
** my_find_prime_sup.c
** File description:
** CPool_Day05_2018
*/

int my_find_prime_sup(int nb)
{
    int i = 1;

    for (nb; i != 0; nb++) {
        for (int n = 2; n <= nb; n++)
            i = (nb % n == 0) ? i + 1 : i;
        if (i == 2)
            return (nb);
        i = 1;
    }
}