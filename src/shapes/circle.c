/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Every function needed to draw a circle
*/

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "framebuffer.h"
#include "circle.h"
#include "random.h"

void draw_circle(framebuffer_t *framebuffer, sfVector2f center,
                unsigned int radius, sfColor color)
{
    int row = center.y - radius;
    int col = center.x - radius;
    int x = 0;
    int y = 0;

    while (row < (center.y + radius)) {
        col = center.x - radius;
        while (col < (center.x + radius)) {
            x = col - center.x;
            y = row - center.y;
            if (pow(x, 2) + pow(y, 2) <= pow(radius, 2))
                my_put_pixel(framebuffer, col, row, color);
            col = col + 1;
        }
        row = row + 1;
    }
}

circle_t *circle_create(int x, int y, unsigned int radius, sfColor color)
{
    circle_t *circle = malloc(sizeof(*circle));

    circle->center.x = x;
    circle->center.y = y;
    circle->speed.x = 0;
    circle->speed.y = 0;
    circle->radius = radius;
    circle->color = color;
    return (circle);
}

void circle_update_speed(circle_t *circle, float x_acceleration,
                        float y_acceleration)
{
    if (circle->speed.x < 0)
        circle->speed.x -= x_acceleration;
    else
        circle->speed.x += x_acceleration;
    if (circle->speed.y < 0)
        circle->speed.y -= y_acceleration;
    else
        circle->speed.y += y_acceleration;
    circle->center.x += circle->speed.x;
    circle->center.y += circle->speed.y;
}

bool circle_bounce(circle_t *circle, int width_limit, int height_limit)
{
    int left_limit = circle->center.x - circle->radius;
    int right_limit = circle->center.x + circle->radius;
    int upper_limit = circle->center.y - circle->radius;
    int lower_limit = circle->center.y + circle->radius;

    if (left_limit < 0 || right_limit > width_limit) {
        circle->speed.x = -circle->speed.x;
        return (true);
    }
    if (upper_limit < 0 || lower_limit > height_limit) {
        circle->speed.y = -circle->speed.y;
        return (true);
    }
    return (false);
}