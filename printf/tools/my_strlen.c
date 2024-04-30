/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "../include/tools.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}
