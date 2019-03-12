/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** CPool_Day04_2018
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int i = my_strlen(str);

    write(1, str, i);
    return (i);
}