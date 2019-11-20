/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for shapes
*/

#ifndef SHAPES_H_
    #define SHAPES_H_

    #include <SFML/Graphics.h>
    #include "framebuffer.h"

    void draw_line(framebuffer_t *framebuffer, sfVector2f point_a,
                sfVector2f point_b, sfColor color);
    void draw_circle(framebuffer_t *framebuffer, sfVector2i center,
                unsigned int radius, sfColor color)
#endif