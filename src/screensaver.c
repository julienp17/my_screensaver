/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Display screensaver
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "framebuffer.h"

void poll_events(sfRenderWindow *window);
void (*get_animation_by_id(unsigned int nb))(framebuffer_t*);
void destroy_all(framebuffer_t *framebuffer, sfSprite *sprite,
                sfTexture *texture, sfRenderWindow *window);

void display_screensaver(void (*play_animation)(framebuffer_t *framebuffer))
{
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, W_BPP};
    sfRenderWindow *window = sfRenderWindow_create(mode, W_TITLE, sfClose, 0);
    framebuffer_t *framebuffer = framebuffer_create(W_WIDTH, W_HEIGHT);
    sfTexture *texture = sfTexture_create(W_WIDTH, W_HEIGHT);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window, W_MAX_FPS);
    while (sfRenderWindow_isOpen(window)) {
        poll_events(window);
        play_animation(framebuffer);
        sfTexture_updateFromPixels(texture, framebuffer->pixels,
                                    W_WIDTH, W_HEIGHT, 0, 0);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    destroy_all(framebuffer, sprite, texture, window);
}

void poll_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void destroy_all(framebuffer_t *framebuffer, sfSprite *sprite,
                sfTexture *texture, sfRenderWindow *window)
{
    framebuffer_destroy(framebuffer);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
}