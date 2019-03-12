/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** PSU_navy_2018
*/

#include "navy.h"

void reset_input(void)
{
    input[0] = 0;
    input[1] = 0;
}

void send_signal(int pid, int type)
{
    kill(pid, (type == 1) ? SIGUSR1 : SIGUSR2);
    pause();
}

void get_input(int nb, siginfo_t *siginfo, void *context)
{
    if (nb == 10)
        input[0]++;
    else if (nb == 12)
        input[1]++;
    input[2] = siginfo->si_pid;
}

void connect(data_t *data, int ac, char **av)
{
    if (ac == 2) {
        my_printf("my_pid: %d\nwaiting for enemy connection...\n",
            data->player_pid);
        pause();
        data->enemy_pid = input[2];
        kill(data->enemy_pid, SIGUSR1);
        my_putstr("\nenemy connected\n");
    } else {
        data->enemy_pid = my_getnbr(av[1]);
        my_printf("my_pid: %d\n", data->player_pid);
        kill(data->enemy_pid, SIGUSR1);
        pause();
        my_putstr("successfully connected\n");
    }
}

int main(int ac, char **av)
{
    data_t *data;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (help_player());
    data = init_navy(ac, av);
    if (data == NULL)
        return (84);
    connect(data, ac, av);
    return (game_loop(data, ac));
}