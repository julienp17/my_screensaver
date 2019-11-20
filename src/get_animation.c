/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Displays animations
*/

#include <stddef.h>
#include "animations.h"
#include "window.h"

void (*get_animation_from_id(unsigned int nb))(window_t*)
{
    unsigned int i = 0;
    void (*animation)(window_t*) = NULL;
    void (*animations[])(window_t*) = {
        &rainbow_rain,
    };

    while (i < nb - 1)
        i = i + 1;
    animation = animations[i];
    return (animation);
}