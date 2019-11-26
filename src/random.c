/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Utilities file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

float get_random_float(float const min, float const max)
{
    return ((float)rand() / (float)(RAND_MAX) * (max - min) + min);
}

sfColor get_random_color(unsigned char opacity)
{
    sfColor color;

    color.r = rand() % 255;
    color.g = rand() % 255;
    color.b = rand() % 255;
    color.a = opacity;
    return (color);
}

sfColor get_black_or_white(void)
{
    return ((rand() % 2) == 0) ? sfWhite : sfBlack;
}