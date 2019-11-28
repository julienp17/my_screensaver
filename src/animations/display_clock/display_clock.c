/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Displays the current time
*/

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include "display_clock.h"
#include "window.h"
#include "shapes.h"

static void draw_clock(window_t *window, my_time_t const *current_time);

void display_clock(window_t *window)
{
    sfClock *clock = sfClock_create();
    my_time_t *current_time = get_current_time(4);

    draw_clock(window, current_time);
    window_refresh(window, &sfBlack);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > 1000) {
            update_time(current_time);
            draw_clock(window, current_time);
            window_refresh(window, &sfBlack);
            sfClock_restart(clock);
        }
    }
}

static void draw_clock(window_t *window, my_time_t const *current_time)
{
    sfVector2f center = {window->width / 2, window->height / 2};

    draw_circle(window->framebuffer, center, window->height / 2, sfWhite);
    draw_circle(window->framebuffer, center, window->height / 2 - 10, sfBlack);
    draw_digital_clock(window, current_time,
                    (sfVector2f) {center.x - 45, center.y + 20}, FONT_SIZE);
}