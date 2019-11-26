/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for struct circle
*/

#ifndef CIRCLE_H_
    #define CIRCLE_H_

    #include <SFML/Graphics.h>
    #include <stdbool.h>

    typedef struct circle {
        sfVector2f center;
        sfVector2f speed;
        unsigned int radius;
        sfColor color;
    } circle_t;

    void draw_circle(framebuffer_t *framebuffer, sfVector2f center,
                unsigned int radius, sfColor color);
    circle_t *circle_create(int x, int y, unsigned int radius, sfColor color);
    void circle_update_speed(circle_t *circle, float x_acceleration,
                        float y_acceleration);
    bool circle_bounce(circle_t *circle, int width_limit, int height_limit);
#endif