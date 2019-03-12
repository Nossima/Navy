/*
** EPITECH PROJECT, 2018
** printf_char_string.c
** File description:
** PSU_my_printf_2018
*/

#include <stdlib.h>
#include "my.h"

char *handle_unprint(char *str)
{
    char *result = malloc_str(1);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < ' ' || str[i] > '~')
            result = my_mstrcat(result,
                my_mstrcat(my_strdup("\\"), dec_to_octal(str[i]), 0), 0);
        else
            result = my_addchar(result, str[i], 1);
    }
    return (result);
}

char *get_string_unprint(char *str, va_list print)
{
    return (my_mstrcat(str, handle_unprint(va_arg(print, char *)), 0));
}

char *get_string(char *str, va_list print)
{
    return (my_mstrcat(str, va_arg(print, char *), 0));
}

char *get_char(char *str, va_list print)
{
    return (my_addchar(str, va_arg(print, int), 1));
}

char *add_percent(char *str, va_list print)
{
    return (my_mstrcat(str, "%", 0));
}