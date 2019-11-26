/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** All functions needed to draw a square
*/

#include <stdlib.h>
#include "framebuffer.h"
#include "square.h"

void draw_square(framebuffer_t *framebuffer, sfVector2i pos,
                unsigned int size, sfColor color)
{
    for (unsigned int i = pos.x ; i < (pos.x + size) ; i++)
        for (unsigned int j = pos.y ; j < (pos.y + size) ; j++)
            my_put_pixel(framebuffer, i, j, color);
}

square_t *square_create(int x, int y, unsigned int size, sfColor color)
{
    square_t *square = malloc(sizeof(*square));

    square->pos.x = x;
    square->pos.y = y;
    square->size  = size;
    square->color = color;
    return (square);
}