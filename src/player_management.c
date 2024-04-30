/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

static int nb_player(mst *soko)
{
    int count = 0;

    for (int i = 0; soko->buffer[i]; i++) {
        if (soko->buffer[i] == 'P')
            count++;
    }
    return count;
}

static int check_line(mst *soko, int i)
{
    for (int j = 0; soko->map[i][j]; j++) {
        if (soko->map[i][j] == 'P') {
            soko->px = i;
            soko->py = j;
            return 0;
        }
    }
    return 84;
}

static int find_player(mst *soko)
{
    for (int i = 0; soko->map[i]; i++) {
        if (check_line(soko, i) == 0)
            return 0;
    }
    return 84;
}

int manage_player(mst *soko)
{
    if (nb_player(soko) != 1) {
        my_puterror("It must have only one player.\n");
        return 84;
    }
    if (find_player(soko) == 84) {
        my_puterror("No player found\n");
        return 84;
    }
    return 0;
}
