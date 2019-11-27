/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Snowflakes moving from left ro right or right to left
*/

#include <stdlib.h>
#include <time.h>
#include "window.h"
#include "blizzard.h"
#include "random.h"
#include "shapes.h"
#include "utils.h"

void blizzard(window_t *window)
{
    snowflake_t **snowflakes = malloc(sizeof(*snowflakes) * NB_SNOWFLAKES);

    for (unsigned int i = 0 ; i < NB_SNOWFLAKES ; i++)
        snowflakes[i] = snowflake_create(window);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        for (unsigned int i = 0 ; i < NB_SNOWFLAKES ; i++) {
            snowflake_update(window, snowflakes[i], SPEED);
            snowflake_display(window, snowflakes[i]);
        }
        window_refresh(window, &(sfColor){BACKGROUND_COLOR});
    }
    for (unsigned int i = 0 ; i < NB_SNOWFLAKES ; i++)
        free(snowflakes[i]);
    free(snowflakes);
}

snowflake_t *snowflake_create(window_t *window)
{
    snowflake_t *snowflake = malloc(sizeof(*snowflake));

    snowflake_get_random_state(window, snowflake);
    return (snowflake);
}

void snowflake_get_random_state(window_t *window, snowflake_t *snowflake)
{
    snowflake->pos.x = get_random_float(-(float)(window->width / 2),
                                    (float)(window->width / 2));
    snowflake->pos.y = get_random_float(-(float)(window->height / 2),
                                    (float)window->height / 2);
    snowflake->pos.z = get_random_float(0.0, (float)window->width / 2);
    snowflake->speed.x = 0.0;
    snowflake->speed.y = 0.0;
    snowflake->color = sfWhite;
}

void snowflake_update(window_t *window, snowflake_t *snowflake,
                    float const speed)
{
    snowflake->pos.z = snowflake->pos.z - speed;
    if (snowflake->pos.z < 1.0)
        snowflake_get_random_state(window, snowflake);
}

void snowflake_display(window_t *window, snowflake_t *snowflake)
{
    snowflake->color = (sfColor) {29, 63, get_random_int(80, 100),
                        map_int(snowflake->pos.z, 0,
                        (float)window->width / 2, 255, 0)};
    snowflake->radius = (unsigned int)map_int(snowflake->pos.z, 0,
                        (float)window->width / 2, MAX_SIZE_SNOWFLAKE, 0);
    snowflake->speed.x = map_float(snowflake->pos.x / snowflake->pos.z, 0, 1,
                                    0, (float)window->width / 2.0);
    snowflake->speed.y = map_float(snowflake->pos.y / snowflake->pos.z, 0, 1,
                                    0, (float)window->height / 2.0);
    draw_circle(window->framebuffer,
                (sfVector2f) {snowflake->speed.x, snowflake->speed.y},
                snowflake->radius, snowflake->color);
}