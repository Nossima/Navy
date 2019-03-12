/*
** EPITECH PROJECT, 2018
** my_str_isupper.c
** File description:
** CPool_Day06_2018
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
    return (1);
}