/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Header file for flower
*/

#ifndef FLOWER_H_
    #define FLOWER_H_

    #include <SFML/Graphics.h>
    #include "window.h"

    #define FRAMERATE               500
    #define SPACING_BEG             4
    #define SPACING_MIN             3
    #define SPACING_MAX             6
    #define DELAY                   1
    #define POINTS_WIDTH            2
    #define FLOWER_1_ANGLE_BEG      137.2
    #define FLOWER_1_COLOR_BEG      sfMagenta
    #define FLOWER_2_ANGLE_BEG      137.6
    #define FLOWER_2_COLOR_BEG      sfYellow
    #define FLOWER_3_ANGLE_BEG      137.5
    #define FLOWER_3_COLOR_BEG      sfCyan

    typedef struct flower {
        sfVector2f center;
        sfVector2f pos;
        unsigned int spacing;
        float angle;
        sfColor color;
    } flower_t;

    flower_t *flower_create(sfVector2f center, unsigned int spacing,
                            float angle, sfColor color);
    flower_t **init_flowers(window_t *window, unsigned int spacing);
#endif