/*
** EPITECH PROJECT, 2019
** My ScreenSaver
** File description:
** Simulation of building windows getting the turn lights on and off
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "shapes.h"
#include "random.h"

static void display_windows(window_t *window, int **windows);
static void update_windows(window_t *window, int **windows);
static int **init_windows(window_t *window);

void building_windows(window_t *window)
{
    int **windows = init_windows(window);
    sfClock *clock = sfClock_create();

    display_windows(window, windows);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > 1000) {
            update_windows(window, windows);
            display_windows(window, windows);
            sfClock_restart(clock);
        }
        window_refresh(window, NULL);
    }
    free(windows);
}

static void display_windows(window_t *window, int **windows)
{
    for (unsigned int i = 0 ; i < window->height / 10 ; i++)
        for (unsigned int j = 0 ; j < window->width / 10 ; j++)
            draw_square(window->framebuffer, (sfVector2f)
                        {j * window->width / 10, i * window->height / 10},
                        window->height / 10,
                        (windows[i][j]) ? sfYellow : sfBlack);
}

static void update_windows(window_t *window, int **windows)
{
    for (unsigned int i = 0 ; i < window->height / 10 ; i++)
        for (unsigned int j = 0 ; j < window->width / 10 ; j++)
            windows[i][j] = get_random_choice_int(0, 1);
}

static int **init_windows(window_t *window)
{
    int **windows = malloc(sizeof(int *) * window->height / 10);

    for (unsigned int i = 0 ; i < window->height / 10 ; i++) {
        windows[i] = malloc(sizeof(int) * window->width / 10);
        for (unsigned int j = 0 ; j < window->width / 10 ; j++)
            windows[i][j] = get_random_choice_int(0, 1);
    }
    return (windows);
}