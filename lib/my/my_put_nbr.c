/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** CPool_Day03_2018
*/

#include "my.h"

int my_put_nbr(int nb)
{
    long temp = nb;

    if (temp < 0) {
        my_putchar('-');
        temp = temp * -1;
    }
    if (temp >= 10) {
        my_put_nbr(temp / 10);
        my_put_nbr(temp % 10);
    } else {
        my_putchar(temp + '0');
    }
    return (temp);
}