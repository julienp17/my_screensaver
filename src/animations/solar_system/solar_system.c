/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Simulation of our solar system
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "shapes.h"
#include "solar_system.h"

void solar_system(window_t *window)
{
    sfVector2f center = {(float)(window->width / 2),
                        (float)(window->height / 2)};
    float x = 0;
    float y = 0;
    float x_2 = 0;
    float y_2 = 0;
    float angle = 0;

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        x = window->width  / 2 + cos(angle) * window->height / 2;
        y = window->height / 2 + sin(angle) * window->height / 2;
        x_2 = window->width  / 2 + cos(angle) * window->height / 4;
        y_2 = window->height / 2 + sin(angle) * window->height / 4;
        angle += 0.1;
        if (angle > PI * 2)
            angle = 0;
        draw_circle_outline(window->framebuffer, center, window->height / 2,
                            sfWhite);
        draw_circle_outline(window->framebuffer, center, window->height / 4,
                            sfWhite);
        draw_circle(window->framebuffer, (sfVector2f){x, y}, 30, sfBlue);
        draw_circle(window->framebuffer, (sfVector2f){x_2, y_2}, 20, sfWhite);
        draw_circle(window->framebuffer, center, 100, sfYellow);
        window_refresh(window, NULL);
    }
}

/*planet_t *planets_create(window_t *window)
{
    planet_t **planets = malloc(sizeof(*planets) * 6);
    planet_t *(*init_planets[])(window_t*) = {
        &
    }

    for (unsigned int i = 0 ; i < 6 ; i++)
        planets[i] = init_planet()
}*/