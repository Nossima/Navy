/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** CPool_Day04_2018
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 0;
    long nbr = 0;

    for (i; str[i] == '-' || str[i] == '+'; i++)
        sign += (str[i] == '-') ? (-1) : (1);
    for (i; str[i] >= '0' && str[i] <= '9'; i++)
        nbr = nbr * 10 + (str[i] - '0');
    if (sign < 0)
        nbr *= -1;
    if (nbr >= -2147483648 && nbr <= 2147483647) {
        return (nbr);
    }
    return (0);
}