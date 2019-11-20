/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Displays a simulation of falling purple rain
*/

#include <stdlib.h>
#include "rainbow_rain.h"
#include "window.h"
#include "shapes.h"

float get_random_float(float const min, float const max);

void rainbow_rain(window_t *window)
{
    droplet_t **droplets = malloc(sizeof(*droplets) * NB_DROPLETS);

    for (unsigned int i = 0 ; i < NB_DROPLETS ; i++)
        droplets[i] = droplet_create();
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        display_droplets(window->framebuffer, droplets);
        window_refresh(window, sfBlack);
    }
    for (unsigned int i = 0 ; i < NB_DROPLETS ; i++)
        free(droplets[i]);
    free(droplets);
}

void display_droplets(framebuffer_t *framebuffer, droplet_t **droplets)
{
    for (unsigned int i = 0 ; i < NB_DROPLETS ; i++) {
        if (droplets[i]->beg.y > 0)
            draw_line(framebuffer, droplets[i]->beg, droplets[i]->end,
                        droplets[i]->color);
        droplet_fall(droplets[i]);
    }
}

droplet_t *droplet_create(void)
{
    droplet_t *droplet = malloc(sizeof(*droplet));

    droplet_get_random_state(droplet);
    return (droplet);
}

void droplet_fall(droplet_t *droplet)
{
    droplet->speed += ACCELERATION;
    droplet->beg.y += droplet->speed;
    droplet->end.y += droplet->speed;
    if (droplet->beg.y >= W_HEIGHT)
        droplet_get_random_state(droplet);
}

void droplet_get_random_state(droplet_t *droplet)
{
    droplet->beg.x = get_random_float(0.0, (float)W_WIDTH);
    droplet->beg.y = get_random_float(0.0, (float)(-W_HEIGHT));
    droplet->len = get_random_float(5.0, 20.0);
    droplet->speed = get_random_float(0.0, 15.0);
    droplet->color = (sfColor) {rand() % 255, rand() % 255, rand() % 255,
                                rand() % (255 - 20) + 20};
    droplet->end.x = droplet->beg.x;
    droplet->end.y = droplet->beg.y + droplet->len;
}