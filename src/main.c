/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Main file for my_screensaver
*/

#include "my_screensaver.h"
#include "my.h"

int main(int ac, char **av)
{
    int error_code = 0;
    int animation_id = 0;

    error_code = check_args(ac, av);
    if (error_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (error_code == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    animation_id = my_strnum_to_uint(av[1]);
    error_code = display_screensaver(animation_id);
    return (MY_EXIT_SUCCESS);
}