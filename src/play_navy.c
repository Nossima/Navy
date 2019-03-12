/*
** EPITECH PROJECT, 2019
** play_navy.c
** File description:
** PSU_navy_2018
*/

#include "navy.h"

void print_maps(data_t *data)
{
    my_putstr("\nmy positions:\n");
    my_show_word_array(data->player_map);
    my_putstr("\nenemy's positions:\n");
    my_show_word_array(data->enemy_map);
}

int server_turn(data_t *data)
{
    print_maps(data);
    send_attack(data);
    if (data->touched[0] == 14 || data->touched[1] == 14
        || data->quit != 0)
        return (1);
    get_attack(data);
    if (data->touched[0] == 14 || data->touched[1] == 14
        || data->quit != 0)
        return (1);
    return (0);
}

int clien_turn(data_t *data)
{
    print_maps(data);
    get_attack(data);
    if (data->touched[0] == 14 || data->touched[1] == 14
        || data->quit != 0)
        return (1);
    send_attack(data);
    if (data->touched[0] == 14 || data->touched[1] == 14
        || data->quit != 0)
        return (1);
    return (0);
}

int game_loop(data_t *data, int ac)
{
    while (data->touched[0] != 14 && data->touched[1] != 14
        && data->quit == 0) {
        if (ac == 2 && server_turn(data) != 0)
            break;
        else if (ac == 3 && clien_turn(data) != 0)
            break;
    }
    if (data->quit != 0)
        return (0);
    print_maps(data);
    my_putstr((data->touched[0] == 14) ? "Enemy won\n" : "I won\n");
    return ((data->touched[0] == 14) ? 1 : 0);
}