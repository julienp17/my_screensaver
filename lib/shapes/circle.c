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