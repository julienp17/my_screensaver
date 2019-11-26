/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Radar
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "line.h"
#include "window.h"

void radar(window_t *window)
{
    sfColor blue = {0, 95, 175, 255};
    sfColor magenta = {255, 95, 215, 255};
    line_t *line1 = line_create((sfVector2f){window->width / 2, 0},
                                (sfVector2f){window->width, 0}, magenta);
    line_t *line2 = line_create((sfVector2f){window->width / 2, window->height},
                                (sfVector2f){0, window->height}, blue);

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        draw_line(window->framebuffer, line1->point_a, line1->point_b, line1->color);
        draw_line(window->framebuffer, line2->point_a, line2->point_b, line2->color);
        if (line1->point_b.y < window->height) {
            line1->point_b.y++;
        } else {
            line1->point_b.x = 0;
            line1->point_b.y = 0;
            line1->color = (sfColor){255, 135, 0, 255};
        }
        if (line2->point_b.y > 0) {
            line2->point_b.y--;
        } else {
            line2->point_b.x = window->width;
            line2->point_b.y = window->height;
            line2->color = (sfColor){215, 255, 135, 255};
        }
        window_refresh(window, NULL);
    }
    free(line1);
    free(line2);
}