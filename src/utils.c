/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Utilities file
*/

#include <stdlib.h>

float get_random_float(float const min, float const max)
{
    return ((float)rand() / (float)(RAND_MAX) * (max - min) + min);
}