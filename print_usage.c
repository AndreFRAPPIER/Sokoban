/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

static int check_arg(char *str)
{
    if (my_strlen(str) < 2) {
        return 84;
    }
    if (str[0] != '-' || str[1] != 'h') {
        return 84;
    }
    return 0;
}

int print_usage(char *arg)
{
    if (check_arg(arg) == 84) {
        return 84;
    }
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n");
    my_putstr("\t\t‘P’ for the player, ‘X’ for boxes and ‘O’ ");
    my_putstr("for storage locations.\n");
}
