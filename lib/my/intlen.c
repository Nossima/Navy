/*
** EPITECH PROJECT, 2018
** intlen.c
** File description:
** PSU_my_printf_2018
*/

int intlen(int nb)
{
    int len = 0;

    for (len; nb > 0; len++)
        nb /= 10;
    return (len);
}