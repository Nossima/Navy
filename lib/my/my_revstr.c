/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** CPool_Day06_2018
*/

#include "my.h"

char *my_revstr(char *str)
{
    int j = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i < j; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return (str);
}