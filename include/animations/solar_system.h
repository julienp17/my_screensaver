/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for solar_system simulation
*/

#ifndef SOLAR_SYSTEM_H
    #define SOLAR_SYSTEM_H

    #include "shapes.h"

    typedef struct planet {
        sfVector2f pos;
        unsigned int radius;
        float radians;
        float revolution_speed;
        sfColor color;
    } planet_t;

#endif