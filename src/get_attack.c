/*
** EPITECH PROJECT, 2019
** get_attack.c
** File description:
** PSU_navy_2018
*/

#include "navy.h"

void check_if_touched(data_t *data, int *attack)
{
    int pos[2] = {attack[1] + 1 - '0', 2 + (2 * (attack[0] - 'A'))};

    pause();
    if (data->player_map[pos[0]][pos[1]] != '.') {
        my_putchar(attack[0]);
        my_printf("%c: hit\n", attack[1]);
        data->player_map[pos[0]][pos[1]] = 'x';
        kill(data->enemy_pid, SIGUSR1);
        data->touched[0]++;
    } else {
        my_putchar(attack[0]);
        my_printf("%c: missed\n", attack[1]);
        data->player_map[pos[0]][pos[1]] = 'o';
        kill(data->enemy_pid, SIGUSR2);
    }
}

void prepare_defense(data_t *data)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    pause();
    kill(data->enemy_pid, SIGUSR1);
    reset_input();
}

void get_attack(data_t *data)
{
    int attack[2];

    prepare_defense(data);
    while (input[1] == 0)
        send_signal(data->enemy_pid, 1);
    if (input[0] == 0) {
        data->quit = 1;
        return;
    }
    attack[0] = 64 + input[0];
    kill(data->enemy_pid, SIGUSR1);
    reset_input();
    while (input[1] == 0)
        send_signal(data->enemy_pid, 1);
    attack[1] = input[0] + '0';
    kill(data->enemy_pid, SIGUSR1);
    check_if_touched(data, attack);
}