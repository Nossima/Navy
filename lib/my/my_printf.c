/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** PSU_my_printf_2018
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *(*transform_arg[11])(char *, va_list) =
    {
        get_int,
        get_string,
        get_char,
        get_bin,
        get_string_unprint,
        get_long,
        decimal_to_octal,
        get_u_dec,
        decimal_to_hexa,
        decimal_to_hexa_caps,
        add_percent
    };

void get_arg(data_t *data, char flag)
{
    for (int i = 0; data->list[i]; i++)
        for (int j = 0; data->list[i][j] != '\0'; j++) {
            data->result = (flag == data->list[i][j]) ?
                transform_arg[i](data->result, data->print) : data->result;
        }
}

void init_list(data_t *data)
{
    data->list = malloc(sizeof(char *) * 12);

    data->list[0] = "id";
    data->list[1] = "s";
    data->list[2] = "c";
    data->list[3] = "b";
    data->list[4] = "S";
    data->list[5] = "l";
    data->list[6] = "o";
    data->list[7] = "u";
    data->list[8] = "x";
    data->list[9] = "X";
    data->list[10] = "%";
    data->list[11] = NULL;
}

int my_printf(char *str, ...)
{
    data_t *data = malloc(sizeof(data_t));

    data->result = my_strdup("");
    init_list(data);
    va_start(data->print, str);
    data->str = str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] != '\0')
            get_arg(data, data->str[i + 1]);
        i += (str[i] == '%' && str[i + 1] != '\0') ? 2 : 0;
        data->result = (data->str[i] != '%') ?
            my_addchar(data->result, data->str[i], 1) : data->result;
    }
    return (my_putstr(data->result));
}