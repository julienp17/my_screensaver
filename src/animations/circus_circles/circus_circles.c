/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Circle that gets bigger and bigger
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "window.h"
#include "circus_circles.h"
#include "random.h"
#include "shapes.h"

void display_circles(window_t *window, sfVector2f center, unsigned int size);

void circus_circles(window_t *window)
{
    sfVector2f center = {window->width / 2, window->height / 2};
    sfClock *clock = sfClock_create();
    unsigned int size = 10;
    unsigned int scale = 1;

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > INTERVAL) {
            display_circles(window, center, size);
            sfClock_restart(clock);
        }
        if (size == 0 || size > window->height / 2 - OUTLINE_DISTANCE)
            scale = -scale;
        size += scale;
        window_refresh(window, NULL);
    }
}

void display_circles(window_t *window, sfVector2f center, unsigned int size)
{
    sfColor random_color = get_random_color(CIRCLES_OPACITY);

    for (int j = size ; j > 0 ; j = j - CIRCLES_DISTANCE) {
        draw_circle(window->framebuffer, center, j + OUTLINE_DISTANCE / 2,
                    random_color);
        draw_circle(window->framebuffer, center, j,
                    get_random_color(CIRCLES_OPACITY));
    }
}