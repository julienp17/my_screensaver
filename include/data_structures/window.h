/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for windows
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <SFML/Graphics.h>
    #include "framebuffer.h"

    #define W_WIDTH         800
    #define W_HEIGHT        600
    #define W_BPP           32
    #define W_MAX_FPS       30
    #define W_TITLE         "My ScreenSaver"

    typedef struct window {
        sfRenderWindow *window;
        unsigned int width;
        unsigned int height;
        framebuffer_t *framebuffer;
        sfTexture *texture;
        sfSprite *sprite;
    } window_t;

    window_t *window_create(unsigned int width, unsigned int height,
                            char const *title);
    void window_refresh(window_t *window, sfColor color);
    void window_destroy(window_t *window);
    void poll_events(sfRenderWindow *window);
#endif