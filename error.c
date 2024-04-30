/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}
