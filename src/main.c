/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Main file for my_screensaver
*/

#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "animations.h"
#include "my_screensaver.h"
#include "my.h"
#include "window.h"

int main(int ac, char **av)
{
    int error_code = 0;
    unsigned int animation_id = 0;
    void (*play_animation)(window_t*) = NULL;
    window_t *window = NULL;

    error_code = check_args(ac, av);
    if (error_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (error_code == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    animation_id = my_strnum_to_uint(av[1]);
    srand(time(NULL));
    play_animation = get_animation_from_id(animation_id);
    if (!play_animation)
        return (MY_EXIT_FAILURE);
    window = window_create(W_WIDTH, W_HEIGHT, W_TITLE);
    play_animation(window);
    window_destroy(window);
    return (MY_EXIT_SUCCESS);
}