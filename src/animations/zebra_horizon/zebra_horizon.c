/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** SInus cosinus animation
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "zebra_horizon.h"
#include "shapes.h"

void zebra_horizon(window_t *window)
{
    line_t *line = line_create((sfVector2f) {0.0, 0.0}, (sfVector2f)
                                {(float)window->width, (float)window->height},
                                sfWhite);
    int line_1_speed = -SPEED;
    int line_2_speed = SPEED;

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        line->point_a.x += line_1_speed;
        line->point_b.x += line_2_speed;
        if (line->point_a.x < -LIMIT || line->point_a.x > LIMIT)
            line_1_speed = -line_1_speed;
        if (line->point_b.x < -LIMIT || line->point_b.x > LIMIT)
            line_2_speed = -line_2_speed;
        draw_line(window->framebuffer, line->point_a, line->point_b, sfWhite);
        window_refresh(window, &sfBlack);
    }
    free(line);
}
