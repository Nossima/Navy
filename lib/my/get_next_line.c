/*
** EPITECH PROJECT, 2019
** getnextline.c
** File description:
** CPE_getnextline_2018
*/

#include "my.h"
/*
char *my_mstrcat(char *dest, char const *src)
{
    int i = 0;
    char *result;
    int len_dest = 0;
    int len_src = 0;

    for (; dest[len_dest] != '\0'; len_dest++);
    for (; src[len_src] != '\0'; len_src++);
    result = malloc(sizeof(char) * (len_dest + len_src + 1));
    if (result == NULL)
        return (NULL);
    for (i; dest[i] != '\0'; i++)
        result[i] = dest[i];
    for (int j = 0; src[j] != '\0'; j++) {
        result[i] = src[j];
        i++;
    }
    result[i] = '\0';
    return (result);
}

char *my_strdup(char const *src)
{
    char *dest;
    int len = 0;

    for (; src[len] != '\0'; len++);
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return (NULL);
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return (dest);
}
*/
char *send_line(char **buffer)
{
    char *line = my_strdup("");
    int i = 0;
    char *add = malloc(sizeof(char) * 2);

    add[1] = '\0';
    if (*buffer == NULL || line == NULL)
        return (NULL);
    for (; (*buffer)[i] != '\n' && (*buffer)[i] != '\0'; i++) {
        add[0] = (*buffer)[i];
        line = my_mstrcat(line, add, 1);
        if (line == NULL)
            return (NULL);
    }
    *buffer = ((*buffer)[i] == '\n') ? &((*buffer)[i + 1]) : NULL;
    line = my_mstrcat(line, "\0", 1);
    if (line == NULL)
        return (NULL);
    return (line);
}

char *read_until_endline(int fd, char *buffer)
{
    char *temp = malloc(sizeof(char) * (READ_SIZE + 1));
    ssize_t size = 1;
    int endline = 0;

    if (temp == NULL)
        return (NULL);
    for (int i = 0; buffer[i] != '\0'; i++)
        endline += (buffer[i] == '\n') ? 1 : 0;
    while (endline == 0 && size > 0) {
        size = read(fd, temp, READ_SIZE);
        temp[size] = '\0';
        if (size <= 0 && (buffer == NULL || buffer[0] == '\0'))
            return (NULL);
        buffer = my_mstrcat(buffer, temp, 0);
        if (buffer == NULL)
            return (NULL);
        for (int i = 0; buffer[i] != '\0'; i++)
            endline += (buffer[i] == '\n') ? 1 : 0;
    }
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *buffer;
    int endline = 0;

    if (fd == -1)
        return (NULL);
    if (!buffer)
        buffer = my_strdup("");
    if (buffer == NULL)
        return (NULL);
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            endline++;
    if (endline == 0)
        buffer = read_until_endline(fd, buffer);
    if (buffer == NULL)
        return (NULL);
    return (send_line(&buffer));
}