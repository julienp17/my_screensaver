/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Simulation of phyllotaxis patterns
*/

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "flower.h"
#include "shapes.h"
#include "utils.h"
#include "random.h"

static void draw_flowers(framebuffer_t *framebuffer, flower_t **flowers,
                        unsigned int time, unsigned int width);
static void get_next_pos(flower_t *flower, unsigned int const time);
static void reset_flowers(flower_t **flowers, unsigned int spacing);
static bool should_reset(window_t *window, flower_t *flower);

void flowers(window_t *window)
{
    unsigned int time = 0;
    flower_t **flowers = init_flowers(window, SPACING_BEG);
    sfClock *clock = sfClock_create();

    sfRenderWindow_setFramerateLimit(window->window, 500);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > DELAY) {
            draw_flowers(window->framebuffer, flowers, time, POINTS_WIDTH);
            time++;
            if (should_reset(window, flowers[0])) {
                framebuffer_clear(window->framebuffer, sfBlack);
                reset_flowers(flowers,get_random_int(SPACING_MIN, SPACING_MAX));
                time = 0;
            }
            window_refresh(window, NULL);
            sfClock_restart(clock);
        }
    }
    free(flowers);
}

static bool should_reset(window_t *window, flower_t *flower)
{
    if (flower->center.y == window->height / 4)
        return (flower->pos.y > window->height);
    else
        return (flower->pos.y < 0);
}

static void draw_flowers(framebuffer_t *framebuffer, flower_t **flowers,
                        unsigned int time, unsigned int width)
{
    for (unsigned int i = 0 ; flowers[i] ; i++) {
        get_next_pos(flowers[i], time);
        if (flowers[i]->pos.x > 0 && flowers[i]->pos.x < framebuffer->width
            && flowers[i]->pos.y > 0 && flowers[i]->pos.y < framebuffer->height)
            draw_circle(framebuffer, flowers[i]->pos, width, flowers[i]->color);
    }
}

static void get_next_pos(flower_t *flower, unsigned int const time)
{
    flower->pos.x = (sqrt(time) * flower->spacing * cos(time * flower->angle))
                    + flower->center.x;
    flower->pos.y = (sqrt(time) * flower->spacing * sin(time * flower->angle))
                    + flower->center.y;
}

static void reset_flowers(flower_t **flowers, unsigned int spacing)
{
    sfColor tmp_color = {0, 0, 0, 0};
    float tmp_y = 0.0;
    float tmp_angle = 0.0;

    for (unsigned int i = 0 ; flowers[i] ; i++)
        flowers[i]->spacing = spacing;
    tmp_color = flowers[0]->color;
    flowers[0]->color = flowers[1]->color;
    flowers[1]->color = flowers[2]->color;
    flowers[2]->color = tmp_color;
    tmp_angle = flowers[2]->angle;
    flowers[2]->angle = flowers[1]->angle;
    flowers[1]->angle = flowers[0]->angle;
    flowers[0]->angle = tmp_angle;
    tmp_y = flowers[2]->center.y;
    flowers[2]->center.y = flowers[0]->center.y;
    flowers[0]->center.y = tmp_y;
}