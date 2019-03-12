/*
** EPITECH PROJECT, 2019
** init_navy.c
** File description:
** PSU_navy_2018
*/

#include "navy.h"

void place_boats(data_t *data, int *position)
{
    char boat = position[4] + '0';

    while (position[4] > 0) {
        data->player_map[position[0]][position[1]] = boat;
        position[position[2]] += position[3];
        position[4]--;
    }
}

int fill_player_map(data_t *data, int fd)
{
    char *boat = get_next_line(fd);
    int position[5];

    if (boat == NULL)
        return (free_navy(data, 3, 84));
    for (; boat != NULL; boat = get_next_line(fd)) {
        position[0] = boat[3] - '0' + 1;
        position[1] = 2 + (2 * (boat[2] - 'A'));
        position[2] = ((boat[6] - '0' + 1) != position[0]) ? 0 : 1;
        if (position[2] == 0)
            position[3] = ((boat[6] - '0' + 1) > position[0]) ? 1 : -1;
        else
            position[3] = (2 + (2 * (boat[5] - 'A')) > position[1]) ? 2 : -2;
        position[4] = boat[0] - '0';
        place_boats(data, position);
        free(boat);
    }
    return (0);
}

void fill_map(data_t *data)
{
    data->player_map[0] = my_strcpy(data->player_map[0], " |A B C D E F G H");
    data->enemy_map[0] = my_strcpy(data->enemy_map[0], " |A B C D E F G H");
    data->player_map[1] = my_strcpy(data->player_map[1], "-+---------------");
    data->enemy_map[1] = my_strcpy(data->enemy_map[1], "-+---------------");
    for (int i = 2; i < 10; i++) {
        data->player_map[i][0] = (i - 1) + '0';
        data->enemy_map[i][0] = (i - 1) + '0';
        data->player_map[i][1] = '|';
        data->enemy_map[i][1] = '|';
        for (int j = 2; j < 17; j++) {
            data->player_map[i][j] = (j % 2 == 0) ? '.' : ' ';
            data->enemy_map[i][j] = (j % 2 == 0) ? '.' : ' ';
        }
    }
}

int init_map(data_t *data, char *path)
{
    int fd;

    if (check_map(path) != 0)
        return (free_navy(data, 1, 84));
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (free_navy(data, 1, 84));
    data->player_map = malloc_tab(11, 19);
    data->enemy_map = malloc_tab(11, 19);
    if (data->player_map == NULL || data->enemy_map == NULL)
        return (free_navy(data, 2, 84));
    fill_map(data);
    fill_player_map(data, fd);
    return (0);
}

data_t *init_navy(int ac, char **av)
{
    data_t *data = malloc(sizeof(data_t));

    if ((ac != 2 && ac != 3) || (ac == 3 && my_str_isnum(av[1]) != 0))
        return (NULL);
    if (data == NULL || init_map(data, (ac == 2) ? av[1] : av[2]) != 0)
        return (NULL);
    data->player_pid = getpid();
    data->enemy_pid = 0;
    for (int i = 0; i < 3; i++)
        input[i] = 0;
    data->touched[0] = 0;
    data->touched[1] = 0;
    data->quit = 0;
    data->sig.sa_flags = SA_SIGINFO;
    data->sig.sa_sigaction = get_input;
    sigemptyset(&data->sig.sa_mask);
    sigaction(10, &data->sig, NULL);
    sigaction(12, &data->sig, NULL);
    return (data);
}