/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

static void manage_event(mst *soko, int key, char *filepath)
{
    if (key == ESC) {
        endwin();
        free_elements(soko);
        exit(0);
    }
    if (key == 0x20) {
        endwin();
        free_elements(soko);
        prepare_sokoban(filepath);
    }
    if (key == KEY_DOWN)
        move_down(soko);
    if (key == KEY_UP)
        move_up(soko);
    if (key == KEY_RIGHT)
        move_right(soko);
    if (key == KEY_LEFT)
        move_left(soko);
}

static void print_map(mst *soko)
{
    for (int line = 0; line < soko->nb_lines; line++)
        mvprintw(line, 0, "%s", soko->map[line]);
}

int my_sokoban(mst *soko, char *filepath)
{
    int key;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
    soko->game_status = 0;
    while (soko->game_status == 0) {
        clear();
        print_map(soko);
        key = getch();
        if (key == -1)
            exit(84);
        manage_event(soko, key, filepath);
        refresh();
        is_game_won(soko);
    }
    endwin();
    free_elements(soko);
    return 0;
}
