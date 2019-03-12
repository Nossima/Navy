/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** CPool_Day01_2018
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
