/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_

    #include "window.h"

    #define MAX_ID          5

    void (*get_animation_from_id(unsigned int nb))(window_t*);
    void rainbow_rain(window_t *window);
    void blizzard(window_t *window);
    void bouncing_ball(window_t *window);
    void circus_circles(window_t *window);
    void game_of_life(window_t *window);
    void radar(window_t *window);
#endif