/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

static int check_line(mst *soko, int i)
{
    int count = 0;

    for (int j = 0; soko->map[i][j]; j++) {
        if (soko->map[i][j] == 'X' && soko->map_save[i][j] == 'O')
            count++;
    }
    return count;
}

void is_game_won(mst *soko)
{
    int complete = 0;

    for (int i = 0; soko->map[i]; i++) {
        complete += check_line(soko, i);
    }
    if (complete == soko->nb_boxes)
        soko->game_status = 1;
}
