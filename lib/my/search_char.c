/*
** EPITECH PROJECT, 2018
** search_char.c
** File description:
** cherche si c est dans str
*/

int search_char(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count++;
    return (count);
}