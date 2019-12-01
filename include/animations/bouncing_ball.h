/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for bouncing ball animation
*/

#ifndef BOUNCING_BALL_H_
    #define BOUNCING_BALL_H_

    #include <SFML/Graphics.h>
    #include "window.h"
    #include "shapes.h"

    #define BALL_SPEED          5

    void bouncing_ball(window_t *window);
    void check_ball_bounce(circle_t *circle, unsigned int width_limit,
                        unsigned int height_limit);
#endif