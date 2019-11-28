/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Draws a seven segment digit in a framebuffer
*/

#include <SFML/Graphics.h>
#include "framebuffer.h"
#include "shapes.h"

sfColor get_opacity(sfColor color, int val, int shift);

void draw_digit(framebuffer_t *framebuffer, char to_display, sfVector2f pos,
                unsigned int size, sfColor color)
{
    int digits[] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
    int digit = digits[to_display - '0'];

    if (to_display < '0' || to_display > '9')
        return;
    draw_rectangle(framebuffer, (sfVector2f) {pos.x + size, pos.y},
                    size * 2, size, get_opacity(color, digit, 6));
    draw_rectangle(framebuffer, (sfVector2f) {pos.x + size * 3, pos.y + size},
                    size, size * 2, get_opacity(color, digit, 5));
    draw_rectangle(framebuffer,(sfVector2f){pos.x + size * 3, pos.y + size * 4},
                    size, size * 2, get_opacity(color, digit, 4));
    draw_rectangle(framebuffer, (sfVector2f) {pos.x + size, pos.y + size * 6},
                    size * 2, size, get_opacity(color, digit, 3));
    draw_rectangle(framebuffer, (sfVector2f) {pos.x, pos.y + size * 4},
                    size, size * 2, get_opacity(color, digit, 2));
    draw_rectangle(framebuffer, (sfVector2f) {pos.x, pos.y + size},
                    size, size * 2, get_opacity(color, digit, 1));
    draw_rectangle(framebuffer, (sfVector2f) {pos.x + size, pos.y + size * 3},
                    size * 2, size, get_opacity(color, digit, 0));
}

sfColor get_opacity(sfColor color, int val, int shift)
{
    color.a = 255 * ((val >> shift) & 1);
    if (color.a == 0)
        color.a = 10;
    return (color);
}