/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Points following a tangent in red, green, and blue
*/

#include <math.h>
#include <SFML/Graphics.h>
#include "window.h"
#include "square.h"
#include "rgb_tan.h"

static sfColor get_next_primary_color(void);

void rgb_tan(window_t *window)
{
    sfColor color = get_next_primary_color();
    float x = 0;
    float y = (float)window->height / 2.0;

    sfRenderWindow_setFramerateLimit(window->window, RGB_TAN_FRAMERATE);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        draw_square(window->framebuffer, (sfVector2i) {x, y},
                    PIXEL_WIDTH, color);
        if (x < window->width) {
            x += 0.1;
            y = (tan(x) * 100.0) + (float)window->height / 2.0;
        } else {
            x = 0;
            color = get_next_primary_color();
        }
        window_refresh(window, NULL);
    }
    sfRenderWindow_setFramerateLimit(window->window, W_MAX_FPS);
}

static sfColor get_next_primary_color(void)
{
    static int index = -1;
    sfColor primary_colors[3] = {sfRed, sfGreen, sfBlue};

    index++;
    if (index > 2)
        index = 0;
    return (primary_colors[index]);
}