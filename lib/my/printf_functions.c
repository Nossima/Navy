/*
** EPITECH PROJECT, 2018
** printf_functions.c
** File description:
** PSU_my_printf_2018
*/

#include <stdlib.h>
#include <limits.h>
#include "my.h"

char *ui_to_char(unsigned int nb)
{
    char *str;
    int len = 0;
    unsigned int number = nb;
    int final;

    for (len; number > 0; len++)
        number /= 10;
    str = malloc(sizeof(char) * (len + 1));
    final = len;
    number = len - 1;
    for (len; len > 0; len--) {
        str[number] = (nb % 10 + 48);
        nb /= 10;
        number--;
    }
    str[final] = '\0';
    return (str);
}

char *get_int(char *str, va_list print)
{
    return (my_mstrcat(str, int_to_char(va_arg(print, int)), 0));
}

char *get_bin(char *str, va_list print)
{
    return (my_mstrcat(str, ui_to_bin(va_arg(print, unsigned int)), 0));
}

char *get_long(char *str, va_list print)
{
    return (my_mstrcat(str, long_to_char(va_arg(print, long int)), 0));
}

char *get_u_dec(char *str, va_list print)
{
    return (my_mstrcat(str, ui_to_char(va_arg(print, unsigned int)), 0));
}