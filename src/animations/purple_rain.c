/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Displays a simulation of falling purple rain
*/

#include "my_screensaver.h"
#include "window.h"
#include "framebuffer.h"
#include "shapes.h"

void purple_rain(window_t *window)
{
    sfVector2f point_a;
    sfVector2f point_b;

    point_a.x = W_WIDTH / 2;
    point_a.y = 0;
    point_b.x = W_WIDTH / 2;
    point_b.y = W_HEIGHT;
    draw_line(window->framebuffer, point_a, point_b, sfRed);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        draw_line(window->framebuffer, point_a, point_b, sfRed);
        point_a.x = point_a.x + 1.0;
        window_refresh(window);
    }
}