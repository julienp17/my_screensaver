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
#include "shapes.h"
#include "random.h"

void draw_circle(framebuffer_t *framebuffer, sfVector2f center,
                unsigned int radius, sfColor color)
{
    for (int y = center.y - radius ; y < (center.y + radius) ; y++) {
        if (y < 0)
            continue;
        else if (y > (int)(framebuffer->height))
            break;
        for (int x = center.x - radius ; x < (center.x + radius) ; x++) {
            if (x < 0)
                continue;
            else if (x > (int)(framebuffer->width))
                break;
            if (pow(x - center.x, 2) + pow(y - center.y, 2) <= pow(radius, 2))
                my_put_pixel(framebuffer, x, y, color);
        }
    }
}

void draw_circle_outline(framebuffer_t *framebuffer, sfVector2f center,
                        unsigned int radius, sfColor color)
{
    draw_circle(framebuffer, center, radius + 1, color);
    draw_circle(framebuffer, center, radius, sfBlack);
}

circle_t *circle_create(float x, float y, unsigned int radius, sfColor color)
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