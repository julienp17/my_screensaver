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
    #include "circle.h"

    #define MAX_X_SPEED         10
    #define MAX_Y_SPEED         10

    void bouncing_ball(window_t *window);
#endif