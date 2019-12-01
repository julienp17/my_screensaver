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

void (*get_animation_from_id(unsigned int animation_id))(window_t*)
{
    void (*animation)(window_t*) = NULL;
    void (*animations[])(window_t*) = {
        &rainbow_rain, &blizzard, &bouncing_ball, &circus_circles,
        &building_windows, &rgb_tan, &random_numbers, &digital_clock,
        &zebra_horizon, &ten_print, &laser, &hamon, &lorenz_attractor,
        &solar_system, &bubble_sort_visualizer, &flowers
    };

    if (animation_id < 1 || animation_id > MAX_ID) {
        my_puterr("Incorrect animation id\nretry with -d\n");
        return (NULL);
    }
    animation = animations[animation_id - 1];
    return (animation);
}