/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Source file for struct flower_t
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "flowers.h"
#include "window.h"

flower_t **init_flowers(window_t *window, unsigned int spacing)
{
    flower_t **flowers = malloc(sizeof(*flowers) * (3 + 1));

    flowers[0] = flower_create((sfVector2f)
                                {window->width / 6, window->height / 4},
                                spacing,
                                FLOWER_1_ANGLE_BEG,
                                FLOWER_1_COLOR_BEG);
    flowers[1] = flower_create((sfVector2f)
                                {window->width / 2, window->height / 2},
                                spacing,
                                FLOWER_2_ANGLE_BEG,
                                FLOWER_2_COLOR_BEG);
    flowers[2] = flower_create((sfVector2f)
                                {window->width * 5 / 6, window->height * 3 / 4},
                                spacing,
                                FLOWER_3_ANGLE_BEG,
                                FLOWER_3_COLOR_BEG);
    flowers[3] = NULL;
    return(flowers);
}

flower_t *flower_create(sfVector2f center, unsigned int spacing, float angle,
                        sfColor color)
{
    flower_t *flower = malloc(sizeof(*flower));

    flower->center  = center;
    flower->pos     = (sfVector2f) {0, 0};
    flower->spacing = spacing;
    flower->angle   = angle;
    flower->color   = color;
    return (flower);
}