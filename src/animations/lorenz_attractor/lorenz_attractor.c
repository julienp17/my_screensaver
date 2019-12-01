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

static void update_point(sfVector3f *point, float const sigma,
                            float const rho, float const beta);
static void draw_point(window_t *window, sfVector3f point);

void lorenz_attractor(window_t *window)
{
    sfVector3f point = {0.01, 0.0, 0.0};
    float const rho = 28.0;
    float const sigma = 10.0;
    float const beta = 8.0 / 3.0;
    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > 10) {
            update_point(&point, sigma, rho, beta);
            draw_point(window, point);
            window_refresh(window, NULL);
            sfClock_restart(clock);
        }
    }
}

static void draw_point(window_t *window, sfVector3f point)
{
    static float hue = 0.0;

    draw_circle(window->framebuffer, (sfVector2f)
                {(point.x * window->width / 100) + window->width / 2,
                (point.y * window->height / 100) + window->height / 2},
                2,
                hsb_to_rgb(hue, 1.0, 1.0, 255));
    hue += 0.5;
    if (hue > 360.0)
        hue = 0.0;
}

static void update_point(sfVector3f *point, float const sigma,
                        float const rho, float const beta)
{
    float dt = 0.01;
    float dx = (sigma * (point->y - point->x)) * dt;
    float dy = ((point->x * (rho - point->z)) - point->y) * dt;
    float dz = ((point->x * point->y) - (beta * point->z)) * dt;

    point->x += dx;
    point->y += dy;
    point->z += dz;
}