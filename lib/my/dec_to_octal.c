/*
** EPITECH PROJECT, 2018
** dec_to_octal.c
** File description:
** PSU_my_printf_2018
*/

#include <stdlib.h>
#include "my.h"

char *dec_to_octal(int nb)
{
    char *octal = malloc_str(5);
    int i = 0;

    for (i; nb != 0; i++) {
        octal[i] = (nb % 8) + 48;
        nb /= 8;
    }
    octal[i] = '\0';
    for (i; my_strlen(octal) < 3; i++) {
        octal[i] = '0';
        octal[i + 1] = '\0';
    }
    my_revstr(octal);
    return (octal);
}
