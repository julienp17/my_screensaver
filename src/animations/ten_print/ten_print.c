/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Reproduce 10print function
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "ten_print.h"
#include "shapes.h"
#include "random.h"

static void draw_slash(framebuffer_t *framebuffer, sfVector2f *slash,
                        unsigned int spacing, int probability);
static void update_slash(window_t *window, sfVector2f *slash,
                        unsigned int *spacing, int *probability);

void ten_print(window_t *window)
{
    sfVector2f slash = {0, 0};
    unsigned int spacing = START_SPACING;
    int probability = START_PROB;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > DELAY) {
            draw_slash(window->framebuffer, &slash, spacing, probability);
            update_slash(window, &slash, &spacing, &probability);
            window_refresh(window, NULL);
        }
    }
}

static void draw_slash(framebuffer_t *framebuffer, sfVector2f *slash,
                        unsigned int spacing, int probability)
{
    if ((rand() % 10) < probability) {
        draw_line(framebuffer, (sfVector2f) {slash->x, slash->y},
            (sfVector2f) {slash->x + spacing, slash->y + spacing}, sfWhite);
    } else {
        draw_line(framebuffer, (sfVector2f) {slash->x + spacing, slash->y},
                (sfVector2f) {slash->x, slash->y + spacing}, sfWhite);
    }
}

static void update_slash(window_t *window, sfVector2f *slash,
                        unsigned int *spacing, int *probability)
{
    slash->x += *spacing;
    if (slash->x > window->width - *spacing) {
        slash->x = 0;
        slash->y += *spacing;
    }
    if (slash->y > window->height - *spacing) {
        slash->x = 0;
        slash->y = 0;
        *spacing = (unsigned int)get_random_int(SPACING_PROB);
        *probability = get_random_int(SLASH_PROB);
        framebuffer_clear(window->framebuffer, sfBlack);
    }
}