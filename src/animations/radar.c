/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Radar
*/

#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "radar.h"
#include "shapes.h"
#include "window.h"

#include <stdio.h>

void radar(window_t *window)
{
    line_t *line1 = line_create((sfVector2f) {window->width / 2, 0},
                                (sfVector2f) {window->width, 0},
                                (sfColor) {DEEP_PINK4, LINES_OPACITY});
    line_t *line2 = line_create((sfVector2f){window->width / 2, window->height},
                                (sfVector2f){0, window->height},
                                (sfColor) {DEEP_SKY_BLUE4, LINES_OPACITY});

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        draw_line(window->framebuffer, line1->point_a, line1->point_b,
                line1->color);
        draw_line(window->framebuffer, line2->point_a, line2->point_b,
                line2->color);
        if (!update_lines_step_1(window, line1, line2)) {
            if (line1->point_b.y < window->height / 2) {
                line1->point_b.x += 0.5;
                line1->point_b.y += 0.5;
            } else {
                line1->point_a = (sfVector2f) {0, window->height / 2};
                line1->point_b = (sfVector2f) {0, 0};
                line1->color   = sfBlack;
            }
            if (line2->point_b.y > window->height / 2) {
                line2->point_b.x -= 0.5;
                line2->point_b.y -= 0.5;
            } else {
                line2->point_a = (sfVector2f) {window->width, window->height / 2};
                line2->point_b = (sfVector2f) {window->width, window->height};
                line2->color   = sfBlack;
            }
        }
        window_refresh(window, NULL);
    }
    free(line1);
    free(line2);
}

bool update_lines_step_1(window_t *window, line_t *line1, line_t *line2)
{
    static bool step_1_finished = false;

    if (step_1_finished)
        return (false);
    if (line2->point_b.y <= 0 && line2->color.g == 150) {
        line1->point_a = (sfVector2f) {window->width / 4, window->height / 2};
        line1->point_b = (sfVector2f) {window->width / 2, 0};
        line1->color   = sfYellow;
        line2->point_a = (sfVector2f) {window->width * 3/4, window->height / 2};
        line2->point_b = (sfVector2f) {window->width / 2, window->height};
        line2->color   = sfWhite;
        step_1_finished = true;
        return (false);
    }
    if (line1->point_b.y < window->height) {
        line1->point_b.y++;
    } else {
        line1->point_b.x = 0;
        line1->point_b.y = 0;
        line1->color = (sfColor) {DARK_ORANGE, LINES_OPACITY};
    }
    if (line2->point_b.y > 0) {
        line2->point_b.y--;
    } else {
        line2->point_b.x = window->width;
        line2->point_b.y = window->height;
        line2->color = (sfColor) {DARK_GREEN, LINES_OPACITY};
    }
    return (true);
}