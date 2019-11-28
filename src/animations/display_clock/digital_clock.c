/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Displays a digital clock
*/

#include "shapes.h"
#include "display_clock.h"

void draw_digital_clock(window_t *window, my_time_t const *current_time,
                        sfVector2f pos, unsigned int size)
{
    draw_digital_time_unit(window, current_time->hours,
                            (sfVector2f) {pos.x - 125, pos.y}, size);
    draw_colon(window, (sfVector2f) {pos.x - 25, pos.y + size * 2},
                size, sfWhite);
    draw_digital_time_unit(window, current_time->minutes,
                            (sfVector2f) {pos.x, pos.y}, size);
    draw_colon(window, (sfVector2f) {pos.x + 100, pos.y + size * 2},
                size, sfWhite);
    draw_digital_time_unit(window, current_time->seconds,
                            (sfVector2f) {pos.x + 125, pos.y}, size);
}

void draw_digital_time_unit(window_t *window, unsigned int time_unit,
                            sfVector2f pos, unsigned int size)
{
    draw_digit(window->framebuffer, (((time_unit / 10) % 10) + '0'),
            (sfVector2f) {pos.x, pos.y}, size, sfWhite);
    draw_digit(window->framebuffer, ((time_unit % 10) + '0'),
            (sfVector2f) {pos.x + 50, pos.y}, size, sfWhite);
}

void draw_colon(window_t *window, sfVector2f pos, unsigned int size,
                sfColor color)
{
    draw_square(window->framebuffer,
            (sfVector2f) {pos.x, pos.y + size}, size, color);
    draw_square(window->framebuffer,
            (sfVector2f) {pos.x, pos.y + size * 3}, size, color);
}