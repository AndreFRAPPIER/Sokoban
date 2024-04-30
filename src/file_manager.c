/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

static error_open(char *filename)
{
    my_putstr("open : ");
    my_putstr(filename);
    my_putstr(": no such file or directory\n");
}

static error_read(char *filename)
{
    my_putstr("read : ");
    my_putstr(filename);
    my_putstr(": can't read file content\n");
}

static int size_of_file(char *filepath)
{
    struct stat stats;

    if (stat(filepath, &stats) != 0)
        return 84;
    return stats.st_size;
}

int read_file(char *filepath, mst *p)
{
    int fd;
    int size = size_of_file(filepath);

    p->buffer = malloc(sizeof(char) * size + 1);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return -1;
    if (read(fd, p->buffer, size) == -1)
        return -1;
    p->buffer[size] = '\0';
    close(fd);
}
