/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/
#include "my.h"

static int return_max(int sign)
{
    int MAX = 2147483647;
    int MIN = -2147483648;

    if (sign == 1)
        return MAX;
    else
        return MIN;
}

int my_getnbr(char const *str)
{
    int n = 0;
    int i = 0;
    int sign = 1;
    int MAX = 2147483647;
    int MIN = -2147483648;

    while (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i] == '-');
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (n > MAX / 10 || (n == MAX / 10 && str[i] - '0' > 7)) {
            return return_max(sign);
        }
        n = 10 * n + (str[i] - '0');
        i++;
    }
    return n * sign;
}
