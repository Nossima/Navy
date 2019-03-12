/*
** EPITECH PROJECT, 2018
** my_sort_word_array.c
** File description:
** CPool_Day10_2018
*/

#include "my.h"

int check_if_sorted(char **tab)
{
    for (int i = 1; tab[i]; i++)
        if (my_strcmp(tab[i - 1], tab[i]) > 0)
            return (84);
    return (0);
}

void sort_tab(char **previous, char **current, char **temp1, char **temp2)
{
    char *temp;

    if (my_strcmp(*temp1, *temp2) > 0) {
        temp = my_strdup(*previous);
        *previous = my_strdup(*current);
        *current = my_strdup(temp);
        temp = my_strdup(*temp1);
        *temp1 = my_strdup(*temp2);
        *temp2 = my_strdup(temp);
    }
}

int my_sort_word_array(char **tab)
{
    char **temp = tab_dup(tab);

    for (int i = 0; temp[i]; i++)
        temp[i] = my_strlowcase(temp[i]);
    while (check_if_sorted(temp) == 84) {
        for (int i = 1; temp[i]; i++)
            sort_tab(&tab[i - 1], &tab[i], &temp[i - 1], &temp[i]);
    }
    return (0);
}