/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** CPool_Day08_2018
*/

#include <stdlib.h>
#include "my.h"

void my_show_rev_word_array(char *const *tab)
{
    int i = 0;

    for (; tab[i]; i++);
    i--;
    for (; i > -1; i--) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
