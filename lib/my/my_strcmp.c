/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** CPool_Day06_2018
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    if (s1[i] == s2[i])
        return (0);
    else if (s1[i] < s2[i])
        return (-1);
    else
        return (1);
}