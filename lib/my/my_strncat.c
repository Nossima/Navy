/*
** EPITECH PROJECT, 2018
** my_strncat.c
** File description:
** CPool_Day07_2018
*/

#include <stdlib.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (my_strlen(dest) + nb + 1));

    for (i; dest[i] != '\0'; i++)
        result[i] = dest[i];
    for (int j = 0; src[j] != '\0' && j != nb; j++) {
        result[i] = src[j];
        i++;
    }
    result[i] = '\0';
    free(dest);
    return (result);
}