/*
** EPITECH PROJECT, 2019
** malloc_tab.c
** File description:
** PSU_my_ls_2018
*/

#include "my.h"

int tab_size(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}

char **malloc_tab(int size, int columns)
{
    char **tab = malloc(sizeof(char *) * (size));

    if (tab == NULL)
        return (NULL);
    for (int i = 0; i < size; i++)
        tab[i] = NULL;
    if (columns == 0)
        return (tab);
    for (int i = 0; i < size - 1; i++) {
        tab[i] = malloc_str(columns);
        if (tab[i] == NULL)
            return (NULL);
    }
    return (tab);
}

char **realloc_tab(char **tab, int size)
{
    char **result = malloc(sizeof(char *) * (size));
    int i = 0;

    if (result == NULL)
        return (NULL);
    if (tab == NULL) {
        result[0] = NULL;
        return (result);
    }
    for (; tab[i]; i++) {
        result[i] = my_strdup(tab[i]);
        free(tab[i]);
    }
    for (; i < size; i++)
        result[i] = NULL;
    free(tab);
    return (result);
}

char **tab_dup(char **tab)
{
    char **result = malloc_tab(1, 0);

    if (result == NULL)
        return (NULL);
    for (int i = 0; tab[i]; i++)
        result = my_addline(result, tab[i]);
    return (result);
}