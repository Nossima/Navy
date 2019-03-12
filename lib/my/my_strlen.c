/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** CPool_Day04_2018
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (i; str[i] != '\0'; i++);
    return (i);
}