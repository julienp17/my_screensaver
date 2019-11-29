/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Handles photons for laser animation
*/

#include <stddef.h>
#include <stdlib.h>
#include "shapes.h"
#include "window.h"
#include "random.h"

float update_photon_speed(float speed);

circle_t **init_photons(window_t *window, unsigned int size, sfColor color)
{
    circle_t **photons = malloc(sizeof(**photons) * (size + 1));
    sfVector2f pos;

    for (unsigned int i = 0 ; i < size ; i++) {
        photons[i] = malloc(sizeof(photons[i]));
        pos = (sfVector2f){
            get_random_float(window->width / 20 + 20, window->width / 2),
            get_random_float(window->height / 6 + 40,
                            window->height * 5 / 6 - 40)
        };
        photons[i] = circle_create(pos.x, pos.y, 3, color);
        photons[i]->speed.x = get_random_float(2.0, 4.0);
    }
    photons[size] = NULL;
    return (photons);
}

void draw_photons(window_t *window, circle_t **photons)
{
    for (unsigned int i = 0 ; photons[i] ; i++)
        draw_circle(window->framebuffer, photons[i]->center,
                    photons[i]->radius, photons[i]->color);
}

void update_photons(window_t *window, circle_t **photons)
{
    unsigned int right_limit = window->width - window->width / 25;
    unsigned int left_limit = window->width / 25;

    for (unsigned int i = 0 ; photons[i] ; i++) {
        photons[i]->center.x += photons[i]->speed.x;
        if (photons[i]->center.x + photons[i]->radius >= right_limit) {
            photons[i]->speed.x = update_photon_speed(photons[i]->speed.x);
            photons[i]->radius = 2;
            photons[i]->color = (sfColor) {255, 255, 0, 125};
        } else if (photons[i]->center.x - photons[i]->radius <= left_limit) {
            photons[i]->speed.x = update_photon_speed(photons[i]->speed.x);
            photons[i]->radius = 3;
            photons[i]->color = (sfColor) {255, 255, 0, 255};
        }
    }
}

float update_photon_speed(float speed)
{
    if (abs((int)speed) < 15.0)
        speed += (speed < 0) ? -1.0 : 1.0;
    return (speed * -1);
}