/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Display screensaver
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "framebuffer.h"

void poll_events(sfRenderWindow *window);
void (*get_animation_by_id(unsigned int nb))(framebuffer_t*);
void destroy_window(window_t *window);

window_t *window_create(unsigned int width, unsigned int height,
                        char const *title)
{
    window_t *window = malloc(sizeof(*window));
    sfVideoMode mode = {width, height, W_BPP};

    window->window = sfRenderWindow_create(mode, title,
                                            sfClose | sfResize, 0);
    window->width = width;
    window->height = height;
    window->framebuffer = framebuffer_create(width, height);
    window->texture = sfTexture_create(width, height);
    window->sprite = sfSprite_create();
    sfSprite_setTexture(window->sprite, window->texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window->window, W_MAX_FPS);
    return (window);
}

void window_refresh(window_t *window, sfColor color)
{
    sfTexture_updateFromPixels(window->texture, window->framebuffer->pixels,
                                window->width, window->height, 0, 0);
    sfRenderWindow_clear(window->window, color);
    sfRenderWindow_drawSprite(window->window, window->sprite, NULL);
    sfRenderWindow_display(window->window);
    framebuffer_clear(window->framebuffer, color);
}

void window_destroy(window_t *window)
{
    framebuffer_destroy(window->framebuffer);
    sfSprite_destroy(window->sprite);
    sfTexture_destroy(window->texture);
    sfRenderWindow_destroy(window->window);
    free(window);
}

void poll_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
}