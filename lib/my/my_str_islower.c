/*
** EPITECH PROJECT, 2018
** my_str_islower.c
** File description:
** CPool_Day06_2018
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
    return (1);
}