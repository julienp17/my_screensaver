/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Frame buffer data structure
*/

#include <stdlib.h>
#include "framebuffer.h"
#include "window.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(*framebuffer));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc((W_BPP / 4) * width * height);
    return (framebuffer);
}

void framebuffer_clear(framebuffer_t *framebuffer, sfColor color)
{
    for (unsigned int row = 0 ; row < framebuffer->height ; row++)
        for (unsigned int col = 0 ; col < framebuffer->width ; col++)
            my_put_pixel(framebuffer, col, row, color);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
                    sfColor color)
{
    unsigned int pos = ((y * framebuffer->width + x) * 4);

    if (pos > (framebuffer->width * framebuffer->height * 4))
        return;
    framebuffer->pixels[pos] = color.r;
    framebuffer->pixels[pos + 1] = color.g;
    framebuffer->pixels[pos + 2] = color.b;
    framebuffer->pixels[pos + 3] = color.a;
}