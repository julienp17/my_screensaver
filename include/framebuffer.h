/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for buffer
*/

#ifndef FRAMEBUFFER_H_
    #define FRAMEBUFFER_H_

    #include <SFML/Graphics.h>

    typedef struct framebuffer {
        unsigned int width;
        unsigned int height;
        sfUint8 *pixels;
    } framebuffer_t;

    framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
    void framebuffer_clear(framebuffer_t *framebuffer);
    void framebuffer_destroy(framebuffer_t *framebuffer);
    void my_put_pixel(framebuffer_t *framebuffer,
                        unsigned int x,
                        unsigned int y,
                        sfColor color);
#endif