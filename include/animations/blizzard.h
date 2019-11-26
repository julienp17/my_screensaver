/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for blizzard animation
*/

#ifndef BLIZZARD_H_
    #define BLIZZARD_H_

    #include "window.h"

    #define NB_SNOWFLAKES        250
    #define SPEED                1.0
    #define MAX_SIZE_SNOWFLAKE   10

    typedef struct snowflake {
        sfVector3f pos;
        sfVector2f speed;
        unsigned int radius;
        sfColor color;
    } snowflake_t;

    void blizzard(window_t *window);
    snowflake_t *snowflake_create(window_t *window);
    void snowflake_get_random_state(window_t *window, snowflake_t *snowflake);
    void snowflake_update(window_t *window, snowflake_t *snowflake,
                        float const speed);
    void snowflake_display(window_t *window, snowflake_t *snowflake);
#endif