/*
** EPITECH PROJECT, 2019
** free_navy.c
** File description:
** PSU_navy_2018
*/

#include "navy.h"

int free_navy(data_t *data, int nb, int value)
{
    (nb > 0) ? free(data) : 0;
    (nb > 1) ? (data->player_map != NULL) ? free_tab(data->player_map) : 0 : 0;
    return (value);
}