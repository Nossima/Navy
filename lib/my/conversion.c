/*
** EPITECH PROJECT, 2018
** conversion.c
** File description:
** PSU_my_printf_2018
*/

#include <stdlib.h>
#include "my.h"

char *ui_to_bin(unsigned int nb)
{
    char *binary = my_strdup("");

    for (; nb > 0; nb /= 2)
        binary = my_addchar(binary, (nb % 2) + '0', 1);
    return (my_revstr(binary));
}

char *decimal_to_octal(char *str, va_list print)
{
    int i = 0;
    char *temp = dec_to_octal(va_arg(print, unsigned int));
    for (; temp[i] == '0'; i++);
    return (my_strcat(str, &temp[i]));
}

char *dec_to_hex(char *str, va_list print, int type)
{
    unsigned int nb = va_arg(print, unsigned int);
    char *result = my_strdup("");

    type = (type == 0) ? 87 : 55;
    for (; nb > 0; nb /= 16) {
        if (nb % 16 < 10)
            result = my_addchar(result, (nb % 16) + 48, 1);
        else
            result = my_addchar(result, (nb % 16) + type, 1);
    }
    return (my_revstr(result));
}

char *decimal_to_hexa(char *str, va_list print)
{
    return (my_strcat(str, dec_to_hex(str, print, 0)));
}

char *decimal_to_hexa_caps(char *str, va_list print)
{
    return (my_strcat(str, dec_to_hex(str, print, 1)));
}
