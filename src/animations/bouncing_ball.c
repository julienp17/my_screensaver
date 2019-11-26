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
#include "circle.h"
#include "random.h"

void ball_update_pos(circle_t *circle);
void ball_update_speed(circle_t *circle, int max_x_speed, int max_y_speed);
bool check_ball_bounce(circle_t *circle, unsigned int width_limit,
                        unsigned int height_limit);

void bouncing_ball(window_t *window)
{
    circle_t *circle = circle_create(window->width / 2, window->height / 2,
                                    40, sfYellow);

    circle->speed.x = get_random_float(-5, 5);
    circle->speed.y = get_random_float(-10, 10);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        ball_update_pos(circle);
        draw_circle(window->framebuffer, circle->center, circle->radius,
                    circle->color);
        if (circle_bounce(circle, W_WIDTH, W_HEIGHT)) {
            ball_update_speed(circle, MAX_X_SPEED, MAX_Y_SPEED);
            circle->color = get_random_color(255);
        }
        window_refresh(window, &sfBlack);
    }
    free(circle);
}

void ball_update_pos(circle_t *circle)
{
    circle->center.x += circle->speed.x;
    circle->center.y += circle->speed.y;
}

void ball_update_speed(circle_t *circle, int max_x_speed, int max_y_speed)
{
    if (abs((int)(circle->speed.x) < max_x_speed)) {
        if (circle->speed.x < 0)
            circle->speed.x -= 0.5;
        else
            circle->speed.x += 0.5;
    }
    if (abs((int)(circle->speed.y) < max_y_speed)) {
        if (circle->speed.y < 0)
            circle->speed.y -= 0.5;
        else
            circle->speed.y += 0.5;
    }
}

bool check_ball_bounce(circle_t *circle, unsigned int width_limit,
                        unsigned int height_limit)
{
    int left_limit  = circle->center.x - circle->radius;
    unsigned int right_limit = circle->center.x + circle->radius;
    int upper_limit = circle->center.y - circle->radius;
    unsigned int lower_limit = circle->center.y + circle->radius;

    if ((left_limit < 0 || right_limit > width_limit)) {
        circle->speed.x = -circle->speed.x;
        return (true);
    }
    if (upper_limit < 0 || lower_limit > height_limit) {
        circle->speed.y = -circle->speed.y;
        return (true);
    }
    return (false);
}

