/*
** EPITECH PROJECT, 2019
** My ScreenSaver
** File description:
** Print a string to standard error
*/

#include <unistd.h>

void my_puterr(char const *str)
{
    for (int i = 0 ; str[i] ; i = i + 1)
        write(2, &str[i], 1);
}