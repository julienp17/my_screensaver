/*
** EPITECH PROJECT, 2019
** My ScreenSaver
** File description:
** Header file for line
*/

#ifndef LINE_H_
    #define LINE_H_

    #include <SFML/Graphics.h>
    #include "framebuffer.h"

    typedef struct line {
        sfVector2f point_a;
        sfVector2f point_b;
        sfColor color;
    } line_t;

    void draw_line(framebuffer_t *framebuffer, sfVector2f point_a,
                    sfVector2f point_b, sfColor color);
    line_t *line_create(sfVector2f point_a, sfVector2f point_b, sfColor color);
#endif