/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Converts a numerical string to an unsigned int
*/

#include <stdbool.h>
#include "my.h"

static bool is_gt_than_limit(char const *strnum);

unsigned int my_strnum_to_uint(char const *strnum)
{
    unsigned int nb = 0;

    if (!my_str_isnum_pos(strnum) || is_gt_than_limit(strnum))
        return (0);
    for (unsigned int i = 0 ; strnum[i] ; i++)
        nb = nb * 10 + strnum[i] - '0';
    return (nb);
}

static bool is_gt_than_limit(char const *strnum)
{
    if (my_strlen(strnum) > UNSIGNED_INT_MAX_LEN)
        return (true);
    if (my_strlen(strnum) == UNSIGNED_INT_MAX_LEN
        && my_strcmp(strnum, UNSIGNED_INT_MAX_STR) > 0) {
        return (true);
    }
    return (false);
}