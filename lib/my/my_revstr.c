/*
** EPITECH PROJECT, 2019
** My_screensaver
** File description:
** Reverses a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int str_len = 0;
    char tmp = ' ';

    str_len = my_strlen(str);
    while (i < (str_len / 2)) {
        tmp = str[i];
        str[i] = str[(str_len - i - 1)];
        str[(str_len - i - 1)] = tmp;
        i = i + 1;
    }
    return (str);
}
