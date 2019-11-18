/*
** EPITECH PROJECT, 2019
** Libmy
** File description:
** Returns true if the given string is numerical and positive, false otherwise
*/

#include <stdbool.h>

bool my_str_isnum_pos(char const *str)
{
    for (unsigned int i = 0 ; str[i] ; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    return (true);
}