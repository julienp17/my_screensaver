/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Visualization of a bubble sort
*/

#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "bubble_sort_visualizer.h"
#include "shapes.h"
#include "random.h"
#include "utils.h"

static int *get_random_array(window_t *window, int *array, unsigned int size);
static void draw_array(window_t *window, int *array, unsigned int spacing,
                        sfColor color);
static void update_array(int *array, unsigned int *i, unsigned int *limit,
                        bool *swapped);
static void reset_parameters(window_t *window, unsigned int *i,
                            unsigned int *limit, unsigned int *spacing);

void bubble_sort_visualizer(window_t *window)
{
    unsigned int spacing = START_SPACING;
    unsigned int i = 0;
    unsigned int limit = (window->width / spacing) - 1;
    int *array = malloc(sizeof(int) * (window->width / MIN_SPACING));
    bool swapped = false;

    array = get_random_array(window, array, window->width / spacing);
    sfRenderWindow_setFramerateLimit(window->window, FRAMERATE);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        draw_array(window, array, spacing, sfWhite);
        update_array(array, &i, &limit, &swapped);
        if (i >= limit && !swapped) {
            reset_parameters(window, &i, &limit, &spacing);
            array = get_random_array(window, array, window->width / spacing);
        }
        window_refresh(window, &sfBlack);
    }
    free(array);
    sfRenderWindow_setFramerateLimit(window->window, W_MAX_FPS);
}

static int *get_random_array(window_t *window, int *array, unsigned int size)
{
    for (unsigned int i = 0 ; i < size ; i++)
        array[i] = rand() % window->height;
    return (array);
}

static void draw_array(window_t *window, int *array, unsigned int spacing,
                        sfColor color)
{
    for (unsigned int i = 0 ; i < window->width / spacing; i++)
        draw_rectangle(window->framebuffer,
                    (sfVector2f) {i * spacing, window->height - array[i]},
                    spacing, array[i], color);
}

static void update_array(int *array, unsigned int *i, unsigned int *limit,
                        bool *swapped)
{
    if (array[*i] > array[*i + 1]) {
        swap_int(array, *i, *i + 1);
        *swapped = true;
    }
    *i = *i + 1;
    if (*i >= *limit && *swapped == true) {
        *i = 0;
        *limit = *limit - 1;
        *swapped = false;
    }
}

static void reset_parameters(window_t *window, unsigned int *i,
                            unsigned int *limit, unsigned int *spacing)
{
    *i = 0;
    *spacing = get_random_int(MIN_SPACING, MAX_SPACING);
    *limit = (window->width / *spacing) - 1;
}