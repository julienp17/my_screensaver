/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** sinus
*/

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "laser.h"
#include "shapes.h"
#include "random.h"

circle_t **init_photons(window_t *window, unsigned int size, sfColor color);
void draw_photons(window_t *window, circle_t **photons);
void update_photons(window_t *window, circle_t **photons);
void draw_mirrors(window_t *window);

void laser(window_t *window)
{
    circle_t **photons = init_photons(window, NB_PHOTONS, sfYellow);
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > DELAY) {
            draw_photons(window, photons);
            draw_mirrors(window);
            update_photons(window, photons);
            sfClock_restart(clock);
            window_refresh(window, &sfBlack);
        }
    }
    for (unsigned int i = 0 ; i < NB_PHOTONS ; i++)
        free(photons[i]);
    free(photons);
}

void draw_mirrors(window_t *window)
{
    unsigned int width  = window->width / 25;
    unsigned int height = window->height / 6;

    draw_rectangle(window->framebuffer, (sfVector2f)
                    {0, height},
                    width,
                    window->height - (height * 2),
                    sfWhite);
    draw_rectangle(window->framebuffer, (sfVector2f)
                    {window->width - width, height},
                    width,
                    window->height - (height * 2),
                    sfWhite);
    draw_line(window->framebuffer, (sfVector2f) {width, height + 25},
            (sfVector2f) {window->width - width, height + 25}, sfWhite);
    draw_line(window->framebuffer,
            (sfVector2f) {width, height * 5 - 25},
            (sfVector2f) {window->width - width, height * 5 - 25}, sfWhite);
}