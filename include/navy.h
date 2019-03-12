/*
** EPITECH PROJECT, 2018
** navy.h
** File description:
** Navy
*/

#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef NAVY_H
#define NAVY_H

#include "my.h"

int input[3];

typedef struct data {
    struct sigaction sig;
    int player_pid;
    int enemy_pid;
    char **player_map;
    char **enemy_map;
    int touched[2];
    int quit;
} data_t;

data_t *init_navy(int ac, char **av);
void get_input(int nb, siginfo_t *siginfo, void *context);
int free_navy(data_t *data, int nb, int value);
int game_loop(data_t *data, int ac);
void print_maps(data_t *data);
void get_attack(data_t *data);
void send_attack(data_t *data);
void send_signal(int pid, int type);
void reset_input(void);
int check_map(char *path);
int help_player(void);

#endif //NAVY_H
