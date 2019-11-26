/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Utilities file
*/

int map_int(int x, int const in_min, int const in_max,
                int const out_min, int const out_max)
{
    return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

float map_float(float x, float const in_min, float const in_max,
                float const out_min, float const out_max)
{
    return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
