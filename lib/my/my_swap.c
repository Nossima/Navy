/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** CPool_Day04_2018
*/

#include "my.h"

void swap_lines(char **a, char **b)
{
    char *temp = my_strdup(*a);

    free(*a);
    *a = my_strdup(*b);
    free(*b);
    *b = my_strdup(temp);
    free(temp);
}

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}