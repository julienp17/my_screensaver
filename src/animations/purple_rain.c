/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Displays a simulation of falling purple rain
*/

#include "window.h"
#include "framebuffer.h"
#include "shapes.h"

void purple_rain(framebuffer_t *framebuffer)
{
    sfVector2f point_a;
    sfVector2f point_b;

    point_a.x = W_WIDTH / 2;
    point_a.y = 0;
    point_b.x = W_WIDTH / 2;
    point_b.y = W_HEIGHT;
    draw_line(framebuffer, point_a, point_b, sfRed);
}