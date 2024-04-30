/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

void free_elements(mst *soko)
{
    free(soko->buffer);
    for (int i = 0; soko->map[i]; i++) {
        free(soko->map[i]);
    }
    free(soko->map);
    free(soko);
}
