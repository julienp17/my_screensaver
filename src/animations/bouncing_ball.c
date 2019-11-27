/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Bouncing ball that gets faster everytime it hits a corner
*/

#include <stdlib.h>
#include <stdbool.h>
#include "bouncing_ball.h"
#include "window.h"
#include "shapes.h"
#include "random.h"

void bouncing_ball(window_t *window)
{
    circle_t *circle = circle_create(window->width / 2, window->height / 2,
                                    BALL_RADIUS, get_random_color(255));

    circle->speed.x = (float)(get_random_choice_int(-BALL_SPEED, BALL_SPEED));
    circle->speed.y = (float)(get_random_choice_int(-BALL_SPEED, BALL_SPEED));
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        check_ball_bounce(circle, window->width, window->height);
        circle->center.x += circle->speed.x;
        circle->center.y += circle->speed.y;
        draw_circle(window->framebuffer, circle->center, circle->radius,
                    circle->color);
        window_refresh(window, &sfBlack);
    }
    free(circle);
}

void check_ball_bounce(circle_t *circle, unsigned int width_limit,
                        unsigned int height_limit)
{
    int left_limit           = circle->center.x - circle->radius;
    unsigned int right_limit = circle->center.x + circle->radius;
    int upper_limit          = circle->center.y - circle->radius;
    unsigned int lower_limit = circle->center.y + circle->radius;

    if (left_limit <= 0 || right_limit >= width_limit) {
        circle->speed.x = -circle->speed.x;
        circle->color = get_random_color(255);
    }
    if (upper_limit <= 0 || lower_limit >= height_limit) {
        circle->speed.y = -circle->speed.y;
        circle->color = get_random_color(255);
    }
}