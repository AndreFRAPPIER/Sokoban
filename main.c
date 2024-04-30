/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_puterror(NB_ARG_ER);
        my_puterror(H_REF);
        return 84;
    }
    if (argc == 2) {
        if (print_usage(argv[1]) == 84)
            return prepare_sokoban(argv[1]);
    }
}
