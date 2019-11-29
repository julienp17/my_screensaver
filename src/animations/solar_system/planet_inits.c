/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Holds planets information
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "solar_system.h"

planet_t *init_earth(void)
{
    planet_t *earth = malloc(sizeof(*earth));

    earth->pos.x = 0;
    earth->pos.y = 0;
    earth->radians = 0;
    earth->revolution_speed = 0.05;
    earth->size = 
}