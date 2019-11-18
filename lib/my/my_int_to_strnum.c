/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Converts an int to a string
*/

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "my.h"

char *my_int_to_strnum(int nb)
{
    char *strnum = malloc(sizeof(char) * (my_intlen(nb) + 2));
    unsigned int i = 0;
    bool is_neg = (nb < 0) ? true : false;

    if (nb < 0) {
        if (nb == INT_MIN)
            return ("-2147483648");
        nb = -nb;
    } else if (nb == 0) {
        return ("0");
    }
    while (nb != 0) {
        strnum[i++] = nb + '0';
        nb = nb / 10;
    }
    if (is_neg)
        strnum[i++] = '-';
    strnum[i] = '\0';
    return (my_revstr(strnum));
}