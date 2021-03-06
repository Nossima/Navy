/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** CPool_Day06_2018
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; i != n && src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}