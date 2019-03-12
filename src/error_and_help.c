/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Error_handling .c
*/

#include "navy.h"

int check_boat(char *boat, int len)
{
    if (boat[2] == boat[5]
        && boat[6] - boat[3] != len && boat[3] - boat[6] != len)
        return (84);
    else if (boat[3] == boat[6]
        && boat[5] - boat[2] != len && boat[2] - boat[5] != len)
        return (84);
    return (0);
}

int check_map(char *path)
{
    int fd = open(path, O_RDONLY);
    char *line;
    int i = 1;

    if (fd < 0)
        return (84);
    line = get_next_line(fd);
    if (line == NULL)
        return (84);
    for (i; line != NULL; i++) {
        if (my_strlen(line) != 7 || i + 1 != line[0] - '0')
            return (84);
        else if (line[2] != line[5] && line[3] != line[6])
            return (84);
        if (check_boat(line, i) != 0)
            return (84);
        free(line);
        line = get_next_line(fd);
    }
    return ((i == 5) ? 0 : 84);
}

int help_player(void)
{
    my_putstr("USAGE\n \t./navy [first_player_pid] navy_positions\n"
        "DESCRIPTION\n\tFirst_player_pid: only for the 2nd "
        "player. Pid of the first player."
        "\n\tNavy_positions: file representing the "
        "positions of the ships.\n");
    return (0);
}