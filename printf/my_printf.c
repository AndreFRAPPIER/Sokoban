/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** printf
*/

#include "include/lib.h"

static void *check_str(char const *format, va_list flag, mlt *p)
{
    if (format[p->i] == '%') {
        p->i++;
        check_commun_flag(format, flag, p);
    } else {
        my_putchar(format[p->i]);
        p->i++;
        p->len++;
    }
    return p;
}

int my_printf(char const *format, ...)
{
    va_list flag;
    mlt *p = malloc(sizeof(mlt));
    int len = 0;

    p->i = 0;
    p->len = 0;
    va_start(flag, format);
    while (format[p->i]) {
        check_str(format, flag, p);
    }
    va_end(flag);
    len = p->len;
    free(p);
    return len;
}
