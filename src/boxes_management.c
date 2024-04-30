/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

static int check_box_loc(mst *soko, int i)
{
    for (int j = 0; soko->map[i][j]; j++) {
        if (soko->map[i][j] == 'X') {
            soko->nb_boxes++;
        }
        if (soko->map[i][j] == 'O') {
            soko->nb_loc++;
        }
    }
}

static int nb_boxes_location(mst *soko)
{
    for (int i = 0; soko->map[i]; i++) {
        check_box_loc(soko, i);
    }
    if (soko->nb_loc == 0 || soko->nb_boxes == 0) {
        my_puterror("It must have at least 1 box and 1 storage location\n");
        return 84;
    }
    if (soko->nb_loc != soko->nb_boxes) {
        my_puterror("Eack box must have a storage location\n");
        return 84;
    }
}

int manage_boxes(mst *soko)
{
    if (nb_boxes_location(soko) == 84) {
        return 84;
    }
}
