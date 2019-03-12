/*
** EPITECH PROJECT, 2018
** my_strlowcase.c
** File description:
** CPool_Day06_2018
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
    return (str);
}