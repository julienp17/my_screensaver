/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Displays animations
*/

#include <stddef.h>
#include "animations.h"
#include "window.h"
#include "my.h"

void (*get_animation_from_id(unsigned int animation_id))(window_t *)
{
    void (*animation)(window_t *) = NULL;
    void (*animations[])(window_t *) = {
        &blizzard, &circus_circles, &rainbow_rain, &flowers,
        &lorenz_attractor, &hamon, &laser, &random_numbers,
        &digital_clock, &ten_print, &zebra_horizon, &building_windows,
        &bouncing_ball, &rgb_tan, &bubble_sort_visualizer
    };

    if (animation_id < 1 || animation_id > MAX_ID) {
        my_puterr("Incorrect animation id\nretry with -d\n");
        return (NULL);
    }
    animation = animations[animation_id - 1];
    return (animation);
}