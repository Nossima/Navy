/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** CPool_Day06_2018
*/

#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;
    int start = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find[j] && start < 0)
            start = i;
        for (j; str[i] == to_find[j] && to_find[j] != '\0'; j++)
            i++;
        if (str[i] != to_find[j] && to_find[j] != '\0' && start >= 0) {
            i = start;
            j = 0;
            start = -1;
        } else if (start >= 0)
            return (&str[start]);
    }
    return (NULL);
}