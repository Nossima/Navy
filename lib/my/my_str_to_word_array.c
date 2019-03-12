/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** CPool_Day08_2018
*/

#include <stdlib.h>
#include "my.h"

char **alloc_dest(char **dest, char const *str)
{
    int word = 0;
    int j = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        word += (str[i] == '_') ? 1 : 0;
    dest = malloc(sizeof(char *) * (word + 2));
    word = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '_') {
            dest[j] = malloc(sizeof(char) * (i - word + 2));
            word = i;
            j++;
        }
    dest[j] = malloc(sizeof(char) * (i - word + 2));
    dest[j + 1] = NULL;
    return (dest);
}

char *clean_str(char *str)
{
    int i = my_strlen(str) - 1;

    for (i; str[i] == '_'; i--);
    str[i + 1] = '\0';
    return (str);
}

char **my_str_to_word_array(char const *str)
{
    char **dest = alloc_dest(dest, str);
    int j = 0;
    int i = 0;

    for (int cursor = 0; str[cursor] != '\0'; cursor++)
        if (str[cursor] == '_') {
            dest[i][j] = '\0';
            i++;
            j = 0;
        } else {
            dest[i][j] = str[cursor];
            j++;
        }
    dest[i][j] = '\0';
    dest[i + 1] = NULL;
    return (dest);
}
