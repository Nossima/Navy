/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** CPool_Day08_2018
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    dest = my_strcpy(dest, src);
    return (dest);
}