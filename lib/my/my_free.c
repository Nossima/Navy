/*
** EPITECH PROJECT, 2019
** my_free.c
** File description:
** PSU_my_ls_2018
*/

#include "my.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}