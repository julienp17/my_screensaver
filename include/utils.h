/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    int map_int(int x, int const in_min, int const in_max,
                int const out_min, int const out_max);
    float map_float(float x, float const in_min, float const in_max,
                float const out_min, float const out_max);
    void swap_int(int *array, int index_1, int index_2);

    sfColor hsb_to_rgb(float hue, float saturation, float brightness,
                    unsigned char opacity);
#endif