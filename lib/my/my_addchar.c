/*
** EPITECH PROJECT, 2018
** my_addchar.c
** File description:
** PSU_my_printf_2018
*/

#include <stdlib.h>
#include "my.h"

char **my_addline(char **tab, char *str)
{
    int i = 0;

    if (tab == NULL)
        tab = malloc_tab(2, 0);
    else {
        for (; tab[i]; i++);
        tab = realloc_tab(tab, tab_size(tab) + 2);
    }
    if (tab == NULL)
        return (NULL);
    tab[i] = my_strdup(str);
    tab[i + 1] = NULL;
    return (tab);
}

char *my_addchar(char *str, char c, int freeable)
{
    int i = 0;
    char *result;

    if (str != NULL && str[0] != '\0') {
        result = malloc(sizeof(char) * (my_strlen(str) + 2));
        for (i; str[i] != '\0'; i++)
            result[i] = str[i];
    } else
        result = malloc(sizeof(char) * 2);
    result[i] = c;
    result[i + 1] = '\0';
    if (freeable != 0 && str != NULL && str[0] != '\0')
        free(str);
    return (result);
}