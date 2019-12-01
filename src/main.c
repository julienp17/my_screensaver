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
#include "usage.h"
#include "my.h"
#include "window.h"
#include "random.h"

int launch_animation(unsigned int animation_id);

int main(int ac, char **av)
{
    int exit_code = 0;
    unsigned int animation_id = 0;

    exit_code = check_args(ac, av);
    if (exit_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (exit_code == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    srand(time(NULL));
    if (my_str_isnum_pos(av[1]))
        animation_id = my_strnum_to_uint(av[1]);
    else
        animation_id = get_random_int(1, MAX_ID);
    exit_code = launch_animation(animation_id);
    if (exit_code == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    return (MY_EXIT_SUCCESS);
}

int launch_animation(unsigned int animation_id)
{
    window_t *window = NULL;
    void (*play_animation)(window_t*) = get_animation_from_id(animation_id);

    if (!play_animation || !window)
        return (MY_EXIT_FAILURE);
    window = window_create(W_WIDTH, W_HEIGHT, W_TITLE);
    play_animation(window);
    window_destroy(window);
    return (MY_EXIT_SUCCESS);
}