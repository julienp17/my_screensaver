/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** All functions needed to draw a rectangle
*/

#include <stdlib.h>
#include "framebuffer.h"
#include "shapes.h"

void draw_rectangle(framebuffer_t *framebuffer, sfVector2f pos,
                unsigned int width, unsigned int height, sfColor color)
{
    for (unsigned int row = pos.y ; row < (pos.y + height) ; row++)
        for (unsigned int col = pos.x ; col < (pos.x + width) ; col++)
            my_put_pixel(framebuffer, col, row, color);
}