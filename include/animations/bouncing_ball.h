/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for bouncing ball animation
*/

#ifndef BOUNCING_BALL_H_
    #define BOUNCING_BALL_H_

    #include <SFML/Graphics.h>

    typedef struct circle {
        sfVector2f center;
        sfVector2f speed;
        unsigned int radius;
        sfColor color;
    } circle_t;
#endif