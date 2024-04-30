/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

static int get_nblines(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i]) {
        if (str[i] == '\n')
            count++;
        i++;
    }
    if (i > 0 && str[i - 1] != '\n')
        count++;
    return count;
}

static int len_column(char *str, int j)
{
    int i = 0;

    while (str[j] != '\n' && str[j] != '\0') {
        j++;
        i++;
    }
    return i;
}

void buffer_to_map(mst *p)
{
    int i_buff = 0;

    p->nb_lines = get_nblines(p->buffer);
    p->map = malloc(sizeof(char *) * p->nb_lines + 1);
    p->map_save = malloc(sizeof(char *) * p->nb_lines + 1);
    for (int i_map = 0; i_map < p->nb_lines; i_map++) {
        p->len_col = len_column(p->buffer, i_buff);
        p->map[i_map] = malloc(sizeof(char) * p->len_col);
        p->map_save[i_map] = malloc(sizeof(char) * p->len_col);
        for (int j_map = 0; j_map < p->len_col; j_map++) {
            p->map[i_map][j_map] = p->buffer[i_buff];
            p->map_save[i_map][j_map] = p->buffer[i_buff];
            i_buff++;
        }
        p->map[i_map][p->len_col] = '\0';
        p->map_save[i_map][p->len_col] = '\0';
        i_buff++;
    }
    p->map[p->nb_lines] = NULL;
    p->map_save[p->nb_lines] = NULL;
}
