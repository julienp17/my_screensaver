/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for purple_rain
*/

#ifndef PURPLE_RAIN_H
    #define PURPLE_RAIN_H

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

    void purple_rain(window_t *window);
    void display_droplets(framebuffer_t *framebuffer, droplet_t **droplets);
    droplet_t *droplet_create(void);
    void droplet_fall(droplet_t *droplet);
    void droplet_get_random_state(droplet_t *droplet);
#endif