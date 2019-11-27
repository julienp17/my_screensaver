/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for rainbow_rain
*/

#ifndef RAINBOW_RAIN_H
    #define RAINBOW_RAIN_H

    #include <SFML/Graphics.h>
    #include "window.h"

    #define NB_DROPLETS             800
    #define ACCELERATION            0.125

    typedef struct droplet {
        sfVector2f beg;
        sfVector2f end;
        float speed;
        float len;
        sfColor color;
    } droplet_t;

    void rainbow_rain(window_t *window);
    void display_droplets(window_t *window, droplet_t **droplets);
    droplet_t *droplet_create(window_t *window);
    void droplet_fall(window_t *window, droplet_t *droplet);
    void droplet_get_random_state(window_t *window, droplet_t *droplet);
#endif