/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Main file for my_screensaver
*/

#include <stddef.h>
#include "animations.h"
#include "framebuffer.h"
#include "my_screensaver.h"
#include "my.h"

void (*get_animation_by_id(unsigned int nb))(framebuffer_t*);

int main(int ac, char **av)
{
    int error_code = 0;
    unsigned int animation_id = 0;
    void (*play_animation)(framebuffer_t*) = NULL;

    error_code = check_args(ac, av);
    if (error_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (error_code == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    animation_id = my_strnum_to_uint(av[1]);
    play_animation = get_animation_by_id(animation_id);
    display_screensaver(play_animation);
    return (MY_EXIT_SUCCESS);
}