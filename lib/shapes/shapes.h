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

    typedef struct line {
        sfVector2f point_a;
        sfVector2f point_b;
        sfColor color;
    } line_t;

    typedef struct square {
        sfVector2i pos;
        unsigned int size;
        sfColor color;
    } square_t;

    typedef struct circle {
        sfVector2f center;
        sfVector2f speed;
        unsigned int radius;
        sfColor color;
    } circle_t;

    void draw_line(framebuffer_t *framebuffer, sfVector2f point_a,
                sfVector2f point_b, sfColor color);
    void draw_circle(framebuffer_t *framebuffer, sfVector2f center,
                unsigned int radius, sfColor color);
    void draw_square(framebuffer_t *framebuffer, sfVector2i pos,
                unsigned int size, sfColor color);
    line_t *line_create(sfVector2f point_a, sfVector2f point_b, sfColor color);
    square_t *square_create(int x, int y, unsigned int size, sfColor color);
    circle_t *circle_create(int x, int y, unsigned int radius, sfColor color);
#endif