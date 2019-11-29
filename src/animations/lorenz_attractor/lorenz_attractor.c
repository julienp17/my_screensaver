/*
** EPITECH PROJECT, 2019
** My ScreenSaver
** File description:
** Simulation of a Lorenz attractor
*/

#include <limits.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "shapes.h"
#include "random.h"
#include "utils.h"

void update_points(sfVector3f *point, float sigma, float phi, float beta);
static void draw_point(window_t *window, sfVector3f point);

void lorenz_attractor(window_t *window)
{
    sfVector3f point = {0.01, 0.0, 0.0};
    float sigma = 20.0;
    float phi = 28.0;
    float beta = 8.0 / 3.0;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > 10) {
            update_points(&point, sigma, phi, beta);
            draw_point(window, point);
            window_refresh(window, NULL);
            sfClock_restart(clock);
        }
    }
}
                         #include <stdio.h>
static void draw_point(window_t *window, sfVector3f point)
{
    static unsigned int int_color = UINT_MAX;

    // alpha--; sfColor_fromInteger()
    int_color -= 256;
    if (int_color < 1684301055)
        int_color = UINT_MAX;
    // printf("0 = %u\n", sfColor_toInteger((sfColor) {100, 100, 100, 255}));
    // printf("1 = %u\n", sfColor_toInteger((sfColor) {100, 100, 101, 255}));
    draw_circle(window->framebuffer, (sfVector2f)
                {(point.x * window->width / 100) + window->width / 2,
                (point.y * window->height / 100) + window->height / 2},
                2,
                sfColor_fromInteger(int_color));
}

void update_points(sfVector3f *point, float sigma, float phi, float beta)
{
    float dt = 0.01;
    float dx = (sigma * (point->y - point->x)) * dt;
    float dy = ((point->x * (phi - point->z)) - point->y) * dt;
    float dz = ((point->x * point->y) - (beta * point->z)) * dt;

    point->x += dx;
    point->y += dy;
    point->z += dz;
}