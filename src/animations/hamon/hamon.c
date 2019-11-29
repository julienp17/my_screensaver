/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Simulation of water ripples
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "shapes.h"
#include "random.h"

static float **init_buffer(window_t *window);
static void swap_buffers(window_t *window, float **buffer_1, float **buffer_2);
void display_ripple(window_t *window, float **current, float **previous,
                    float damping);

void hamon(window_t *window)
{
    float **current = init_buffer(window);
    float **previous = init_buffer(window);
    float damping = 0.991;
    sfClock *clock = sfClock_create();
    sfClock *drop_interval = sfClock_create();

    previous[rand() % window->height][rand() % window->width] = 255.0;
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(drop_interval).microseconds / 1000 > 2000) {
            previous[rand() % window->height][rand() % window->width] = 255.0;
            sfClock_restart(drop_interval);
        }
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > 10) {
            display_ripple(window, current, previous, damping);
            window_refresh(window, &sfBlack);
            sfClock_restart(clock);
        }
    }
}

void display_ripple(window_t *window, float **current, float **previous,
                    float damping)
{
    for (unsigned int row = 1 ; row < window->height - 1 ; row++) {
        for (unsigned int col = 1 ; col < window->width - 1 ; col++) {
            current[row][col] = ((previous[row - 1][col]
                                + previous[row + 1][col]
                                + previous[row][col - 1]
                                + previous[row][col + 1]) / 2
                                - current[row][col]);
            current[row][col] *= damping;
            my_put_pixel(window->framebuffer, col, row,
                        sfColor_fromInteger((int)current[row][col]));
        }
    }
    swap_buffers(window, current, previous);
}

static float **init_buffer(window_t *window)
{
    float **buffer = malloc(sizeof(float *) * window->height);

    for (unsigned int i = 0 ; i < window->height ; i++) {
        buffer[i] = malloc(sizeof(float) * window->width);
        for (unsigned int j = 0 ; j < window->width ; j++)
            buffer[i][j] = 0.0;
    }
    return (buffer);
}

static void swap_buffers(window_t *window, float **buffer_1, float **buffer_2)
{
    float **tmp = malloc(sizeof(float *) * window->height);

    for (unsigned int i = 0 ; i < window->height ; i++) {
        tmp[i] = malloc(sizeof(float) * window->width);
        for (unsigned int j = 0 ; j < window->width ; j++) {
            tmp[i][j] = buffer_1[i][j];
            buffer_1[i][j] = buffer_2[i][j];
            buffer_2[i][j] = tmp[i][j];
        }
    }
    for (unsigned int i = 0 ; i < window->height ; i++)
        free(tmp[i]);
    free(tmp);
}