/*
** EPITECH PROJECT, 2018
** my_strcapitalize.c
** File description:
** CPool_Day06_2018
*/

#include "my.h"

int is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    else if (c >= 'a' && c <= 'z')
        return (0);
    return (84);
}

int is_number(char c)
{
    if (c >= '0' && c <= '9')
        return (0);
    return (84);
}

char *my_strcapitalize(char *str)
{
    int i = 0;
    int is_word = 0;

    my_strlowcase(str);
    for (i; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) != 84) {
            str[i] = (is_word == 0) ? str[i] - 32 : str[i];
            is_word = 1;
        } else if (is_number(str[i]) == 0)
            is_word = 1;
        else
            is_word = 0;
    }
    return (str);
}