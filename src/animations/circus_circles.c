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
#include "circle.h"

void display_circles(window_t *window, sfVector2f center, unsigned int index);

void circus_circles(window_t *window)
{
    sfVector2f center = {window->width / 2, window->height / 2};
    sfClock *clock = sfClock_create();
    unsigned int i = 0;

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > INTERVAL) {
            display_circles(window, center, i);
            sfClock_restart(clock);
        }
        if (i < window->height / 2)
            i++;
        window_refresh(window, NULL);
    }
}

void display_circles(window_t *window, sfVector2f center, unsigned int index)
{
    sfColor random_color;

    if (index < window->height / 2) {
        for (int j = index ; j > 0 ; j = j - CIRCLES_DISTANCE){
            draw_circle(window->framebuffer, center, j + 10,
                        get_random_color(CIRCLES_OPACITY));
            draw_circle(window->framebuffer, center, j,
                        get_random_color(CIRCLES_OPACITY));
        }
    } else {
        random_color = get_random_color(CIRCLES_OPACITY);
        for (int j = index ; j > 0 ; j = j - CIRCLES_DISTANCE) {
            draw_circle(window->framebuffer, center, j + 10,
                        get_random_color(CIRCLES_OPACITY));
            draw_circle(window->framebuffer, center, j, random_color);
        }
    }
}