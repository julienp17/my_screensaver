/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for struct square
*/

#ifndef SQUARE_H_
    #define SQUARE_H_

    #include <SFML/Graphics.h>

    typedef struct square {
        sfVector2i pos;
        unsigned int size;
        sfColor color;
    } square_t;

    void draw_square(framebuffer_t *framebuffer, sfVector2i pos,
                unsigned int size, sfColor color);
    square_t *square_create(int x, int y, unsigned int size, sfColor color);
#endif