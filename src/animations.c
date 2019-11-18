/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Displays animations
*/

#include <stddef.h>
#include "animations.h"
#include "framebuffer.h"

void (*get_animation_by_id(unsigned int nb))(framebuffer_t*)
{
    unsigned int i = 0;
    void (*animation)(framebuffer_t*) = NULL;
    void (*animations[])(framebuffer_t*) = {
        &purple_rain,
        &starfield
    };

    while (i < nb - 1)
        i = i + 1;
    animation = animations[i];
    return (animation);
}