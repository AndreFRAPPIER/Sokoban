/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

static int check_buffer(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' &&
        str[i] != 'P' &&
        str[i] != 'X' &&
        str[i] != 'O' &&
        str[i] != '\n' &&
        str[i] != '#')
            return 84;
    }
    return 0;
}

static void save_map(mst *soko)
{
    soko->map_save = malloc(sizeof(char *) * soko->nb_lines + 1);
    for (int i = 0; i < soko->nb_lines; i++) {
        soko->map_save[i] = malloc(sizeof(char) * soko->len_col + 1);
        soko->map_save[i] = soko->map[i];
    }
    soko->map_save[soko->nb_lines] = NULL;
}

int prepare_sokoban(char *filepath)
{
    mst *soko = malloc(sizeof(mst));

    read_file(filepath, soko);
    if (check_buffer(soko->buffer) == 84) {
        my_puterror(BUFF_ERROR);
        free(soko->buffer);
        free(soko);
        return 84;
    }
    buffer_to_map(soko);
    if (find_elements(soko) == 84) {
        free_elements(soko);
        return 84;
    }
    return my_sokoban(soko, filepath);
}
