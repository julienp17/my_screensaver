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

void poll_events(sfRenderWindow *window, sfEvent *event);
void (*get_animation_by_id(unsigned int nb))(framebuffer_t*);

int display_screensaver(unsigned int animation_id)
{
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, W_BPP};
    sfRenderWindow *window = NULL;
    sfEvent event;
    framebuffer_t *framebuffer = framebuffer_create(W_WIDTH, W_HEIGHT);
    void (*play_animation)(framebuffer_t*) = NULL;

    window = sfRenderWindow_create(mode, W_TITLE, sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        poll_events(window, &event);
        play_animation = get_animation_by_id(animation_id);
        sfRenderWindow_clear(window, sfBlack);
        play_animation(framebuffer);
        sfRenderWindow_display(window);
    }
    framebuffer_destroy(framebuffer);
    sfRenderWindow_destroy(window);
    return (0);
}

void poll_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}