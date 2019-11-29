/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_

    #include "window.h"

    #define MAX_ID          12

    void (*get_animation_from_id(unsigned int nb))(window_t*);
    void rainbow_rain(window_t *window);
    void blizzard(window_t *window);
    void bouncing_ball(window_t *window);
    void circus_circles(window_t *window);
    void building_windows(window_t *window);
    void rgb_tan(window_t *window);
    void random_numbers(window_t *window);
    void display_clock(window_t *window);
    void zebra_horizon(window_t *window);
    void ten_print(window_t *window);
    void laser(window_t *window);
    void hamon(window_t *window);
#endif