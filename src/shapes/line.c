/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Every function needed to draw a line
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "framebuffer.h"
#include "line.h"

void draw_line(framebuffer_t *framebuffer, sfVector2f point_a,
                sfVector2f point_b, sfColor color)
{
    int dx = point_b.x - point_a.x;
    int dy = point_b.y - point_a.y;
    float x = point_a.x;
    float y = point_a.y;
    unsigned int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    for (unsigned int i = 0 ; i < steps + 1 ; i = i + 1) {
        my_put_pixel(framebuffer, x, y, color);
        x = x + (dx / (float)steps);
        y = y + (dy / (float)steps);
    }
}

line_t *line_create(sfVector2f point_a, sfVector2f point_b, sfColor color)
{
    line_t *line = malloc(sizeof(*line));

    line->point_a = point_a;
    line->point_b = point_b;
    line->color = color;
    return (line);
}