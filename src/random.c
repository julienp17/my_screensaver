/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Utilities file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>

int get_random_int(int const min, int const max)
{
    return ((rand() % (max - min + 1)) + min);
}

int get_random_choice_int(int choice1, int choice2)
{
    return ((rand() % 2 == 0) ? choice1 : choice2);
}

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