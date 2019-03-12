/*
** EPITECH PROJECT, 2019
** manage_attacks.c
** File description:
** PSU_navy_2018
*/

#include "navy.h"

int check_attack(char *str, char **map)
{
    if (str[0] < 'A' || str[0] > 'H' || str[1] < '1' || str[1] > '8') {
        free(str);
        my_putstr("wrong position");
        return (84);
    } else if (map[str[1] + 1 - '0'][2 + (2 * (str[0] - 'A'))] != '.') {
        free(str);
        my_putstr("wrong position");
        return (84);
    }
    return (0);
}

void check_if_enemy_touched(data_t *data, int *attack)
{
    int pos[2] = {attack[1] + 1 - '0', 2 + (2 * (attack[0] - 'A'))};

    reset_input();
    send_signal(data->enemy_pid, 1);
    if (input[0] > input[1]) {
        my_putchar(attack[0]);
        my_printf("%c: hit\n", attack[1]);
        data->enemy_map[pos[0]][pos[1]] = 'x';
        data->touched[1]++;
    } else {
        my_putchar(attack[0]);
        my_printf("%c: missed\n", attack[1]);
        data->enemy_map[pos[0]][pos[1]] = 'o';
    }
}

void end_navy(data_t *data)
{
    data->quit = 1;
    send_signal(data->enemy_pid, 1);
    kill(data->enemy_pid, SIGUSR2);
}

void send_attack(data_t *data)
{
    char *attack;
    int pos[2];

    my_putstr("\nattack: ");
    attack = get_next_line(0);
    if (attack == NULL) {
        end_navy(data);
        return;
    } else if (check_attack(attack, data->enemy_map) != 0)
        send_attack(data);
    send_signal(data->enemy_pid, 1);
    for (int i = 64; i < attack[0]; i++)
        send_signal(data->enemy_pid, 1);
    send_signal(data->enemy_pid, 2);
    for (int i = 48; i < attack[1]; i++)
        send_signal(data->enemy_pid, 1);
    send_signal(data->enemy_pid, 2);
    pos[0] = attack[0];
    pos[1] = attack[1];
    check_if_enemy_touched(data, pos);
}