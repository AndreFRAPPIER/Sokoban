/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#ifndef MY_H
    #define MY_H
    #define NB_ARG_ER "Wrong number of arguments passed to the prog.\n"
    #define H_REF "-> Please refer for usage to \n\n\t my_hunter -h\n\n"
    #define BUFF_ERROR "Map have to be filled only with # ' ' P and O\n"
    #define ESC 27
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <ncurses.h>

typedef struct sokoban {
    char *buffer;
    char **map;
    char **map_save;
    int nb_lines;
    int len_col;
    int px;
    int py;
    int nb_boxes;
    int nb_loc;
    int game_status;
    char save;
} mst;

int my_printf(char const *format, ...);
void my_puterror(char *str);
int print_usage(char *arg);
int prepare_sokoban(char *filepath);
int read_file(char *filepath, mst *p);
int my_getnbr(char const *str);
void buffer_to_map(mst *p);
int find_elements(mst *soko);
int manage_player(mst *soko);
int manage_boxes(mst *soko);
void free_elements(mst *soko);
int my_sokoban(mst *soko, char *filepath);
void is_game_won(mst *soko);
void move_down(mst *soko);
void move_up(mst *soko);
void move_right(mst *soko);

#endif /* !MY_H */
