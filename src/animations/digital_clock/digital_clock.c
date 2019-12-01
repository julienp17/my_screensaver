/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Displays the current time
*/

#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.h>
#include "digital_clock.h"
#include "window.h"
#include "shapes.h"

static void draw_clock(window_t *window, my_time_t const *current_time,
                        unsigned int size);
static void draw_digital_clock(window_t *window, my_time_t const *current_time,
                                sfVector2f pos, unsigned int size);
static void draw_digital_time_unit(window_t *window, unsigned int time_unit,
                                    sfVector2f pos, unsigned int size);
static void draw_colon(window_t *window, sfVector2f pos, unsigned int size,
                        sfColor color);

void digital_clock(window_t *window)
{
    sfClock *clock = sfClock_create();
    my_time_t *current_time = get_current_time(REUNION_GMT);

    draw_clock(window, current_time, FONT_SIZE);
    window_refresh(window, &sfBlack);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        if (sfClock_getElapsedTime(clock).microseconds / 1000 > DELAY) {
            update_time(current_time);
            draw_clock(window, current_time, FONT_SIZE);
            window_refresh(window, &sfBlack);
            sfClock_restart(clock);
        }
    }
}

static void draw_clock(window_t *window, my_time_t const *current_time,
                        unsigned int size)
{
    sfVector2f center = {window->width / 2, window->height / 2};

    draw_circle(window->framebuffer, center, window->height / 2, sfWhite);
    draw_circle(window->framebuffer, center, window->height / 2 - 10, sfBlack);
    draw_digital_clock(window, current_time, (sfVector2f)
                    {center.x - size * 3.5, center.y - size * 3.5}, size);
}

static void draw_digital_clock(window_t *window, my_time_t const *current_time,
                        sfVector2f pos, unsigned int size)
{
    draw_digital_time_unit(window, current_time->hours,
                            (sfVector2f) {pos.x - size * 14, pos.y}, size);
    draw_colon(window, (sfVector2f) {pos.x - size * 3, pos.y + size * 2},
                size, sfWhite);
    draw_digital_time_unit(window, current_time->minutes,
                            (sfVector2f) {pos.x - size, pos.y}, size);
    draw_colon(window, (sfVector2f) {pos.x + size * 10, pos.y + size * 2},
                size, sfWhite);
    draw_digital_time_unit(window, current_time->seconds,
                            (sfVector2f) {pos.x + size * 12, pos.y}, size);
}

static void draw_digital_time_unit(window_t *window, unsigned int time_unit,
                            sfVector2f pos, unsigned int size)
{
    draw_digit(window->framebuffer, (((time_unit / 10) % 10) + '0'),
            (sfVector2f) {pos.x, pos.y}, size, sfWhite);
    draw_digit(window->framebuffer, ((time_unit % 10) + '0'),
            (sfVector2f) {pos.x + size * 5, pos.y}, size, sfWhite);
}

static void draw_colon(window_t *window, sfVector2f pos, unsigned int size,
                sfColor color)
{
    draw_square(window->framebuffer,
            (sfVector2f) {pos.x, pos.y + size}, size, color);
    draw_square(window->framebuffer,
            (sfVector2f) {pos.x, pos.y + size * 3}, size, color);
}