/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Random numbers passing by the screen in green
*/

#include <stdlib.h>
#include "window.h"
#include "random_numbers.h"
#include "shapes.h"
#include "random.h"

static void display_random_numbers(window_t *window, int y);

void random_numbers(window_t *window)
{
    sfClock *clock = sfClock_create();

    window_refresh(window, &sfBlack);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > DELAY) {
        display_random_numbers(window, 0 + OFFSET);
        display_random_numbers(window, window->height / 3 + OFFSET);
        display_random_numbers(window, window->height / 1.5 + OFFSET);
        window_refresh(window, &sfBlack);
        sfClock_restart(clock);
    }
    }
}

static void display_random_numbers(window_t *window, int y)
{
    for (unsigned int x = OFFSET ; x < window->width ; x += window->width / 10)
        draw_digit(window->framebuffer, (rand() % 10 + '0'),
                    (sfVector2f) {x, y}, 20, sfGreen);
}