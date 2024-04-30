/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

static void move_box_down(mst *soko)
{
    if (soko->map_save[soko->px][soko->py] == 'O')
        soko->map[soko->px][soko->py] = 'O';
    else
        soko->map[soko->px][soko->py] = ' ';
    soko->map[soko->px + 2][soko->py] = 'X';
    soko->map[soko->px + 1][soko->py] = 'P';
    soko->px++;
}

static void move_box_up(mst *soko)
{
    if (soko->map_save[soko->px][soko->py] == 'O')
        soko->map[soko->px][soko->py] = 'O';
    else
        soko->map[soko->px][soko->py] = ' ';
    soko->map[soko->px - 2][soko->py] = 'X';
    soko->map[soko->px - 1][soko->py] = 'P';
    soko->px--;
}

static void move_box_right(mst *soko)
{
    if (soko->map_save[soko->px][soko->py] == 'O')
        soko->map[soko->px][soko->py] = 'O';
    else
        soko->map[soko->px][soko->py] = ' ';
    soko->map[soko->px][soko->py + 2] = 'X';
    soko->map[soko->px][soko->py + 1] = 'P';
    soko->py++;
}

static void move_box_left(mst *soko)
{
    if (soko->map_save[soko->px][soko->py] == 'O')
        soko->map[soko->px][soko->py] = 'O';
    else
        soko->map[soko->px][soko->py] = ' ';
    soko->map[soko->px][soko->py - 2] = 'X';
    soko->map[soko->px][soko->py - 1] = 'P';
    soko->py--;
}

void move_down(mst *soko)
{
    if (soko->map[soko->px + 1][soko->py] != '#' &&
    soko->map[soko->px + 1][soko->py] != 'X') {
        if (soko->map_save[soko->px][soko->py] == 'O')
            soko->map[soko->px][soko->py] = 'O';
        else
            soko->map[soko->px][soko->py] = ' ';
        soko->map[soko->px + 1][soko->py] = 'P';
        soko->px++;
    } else if (soko->map[soko->px + 1][soko->py] == 'X' &&
    soko->map[soko->px + 2][soko->py] != '#')
        move_box_down(soko);
}

void move_up(mst *soko)
{
    if (soko->map[soko->px - 1][soko->py] != '#' &&
    soko->map[soko->px - 1][soko->py] != 'X') {
        if (soko->map_save[soko->px][soko->py] == 'O')
            soko->map[soko->px][soko->py] = 'O';
        else
            soko->map[soko->px][soko->py] = ' ';
        soko->map[soko->px - 1][soko->py] = 'P';
        soko->px--;
    } else if (soko->map[soko->px - 1][soko->py] == 'X' &&
    soko->map[soko->px - 2][soko->py] != '#')
        move_box_up(soko);
}

void move_right(mst *soko)
{
    if (soko->map[soko->px][soko->py + 1] != '#' &&
    soko->map[soko->px][soko->py + 1] != 'X') {
        if (soko->map_save[soko->px][soko->py] == 'O')
            soko->map[soko->px][soko->py] = 'O';
        else
            soko->map[soko->px][soko->py] = ' ';
        soko->map[soko->px][soko->py + 1] = 'P';
        soko->py++;
    } else if (soko->map[soko->px][soko->py + 1] == 'X' &&
    soko->map[soko->px][soko->py + 2] != '#')
        move_box_right(soko);
}

void move_left(mst *soko)
{
    if (soko->map[soko->px][soko->py - 1] != '#' &&
    soko->map[soko->px][soko->py - 1] != 'X') {
        if (soko->map_save[soko->px][soko->py] == 'O')
            soko->map[soko->px][soko->py] = 'O';
        else
            soko->map[soko->px][soko->py] = ' ';
        soko->map[soko->px][soko->py - 1] = 'P';
        soko->py--;
    } else if (soko->map[soko->px][soko->py - 1] == 'X' &&
    soko->map[soko->px][soko->py - 2] != '#')
        move_box_left(soko);
}
