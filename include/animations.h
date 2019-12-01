/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_

    #include "window.h"

    #define MAX_ID      15
    #define RAINBOW_RAIN_DESCRIPTION \
        "1: rainbow rain: multicolor lines falling down the screen."
    #define BLIZZARD_DESCRIPTION \
        "2: blizzard: dark blue circles moving towards you from the left " \
        "of the window to the right."
    #define BOUNCING_BALL_DESCRIPTION \
        "3: bouncing ball: big circle moving in the window and boucing when " \
        "it hits a border."
    #define CIRCUS_CIRCLES_DESCRIPTION \
        "4: circus circles: circle in the center of the screen that scales " \
        "then shrinks and changes color randomly."
    #define BUILDING_WINDOWS_DESCRIPTION \
        "5: building window: grid of yellow squares that either appear or " \
        "disappear."
    #define RGB_TAN_DESCRIPTION \
        "6: rgb tan: a multitude of points being drawn from the left of the " \
        "screen to the right that reset position and changes primary color " \
        "when they exceed the window width."
    #define RANDOM_NUMBERS_DESCRIPTION \
        "7: random numbers: 3 rows of seven segment display random numbers " \
        "that updates every second in green."
    #define DIGITAL_CLOCK_DESCRIPTION \
        "8: digital clock: an accurate digital clock in Reunion Island GMT " \
        "drawn with seven segment display numbers in a white circle outline."
    #define ZEBRA_HORIZON_DESCRIPTION \
        "9: zebra horizon: white stripes zooming out to infinity."
    #define TEN_PRINT_DESCRIPTION \
        "10: ten print: slashes being drawn from the top left of the screen " \
        "to the bottom right, resulting in a maze."
    #define LASER_DESCRIPTION \
        "11: laser: photons rotating in circles around mirrors and speeding "\
        "up in the process."
    #define HAMON_DESCRIPTION \
        "12: hamon: randomly created water ripples every second."
    #define LORENZ_ATTRACTOR_DESCRIPTION \
        "13: lorenz attractor: points drawn following the lorenz system and " \
        "changing color following a raising hue."
    #define BUBBLE_SORT_VISUALIZER_DESCRIPTION \
        "14: bubble sort visualizer: a visualization of the bubble sort " \
        "algorithm."
    #define FLOWERS_DESCRIPTION \
        "15: flowers: 3 flowers, each with a different phyllotaxis, being " \
        "drawn on the left, center, and right side of the screen that swaps " \
        "position and color when they reset."

    void (*get_animation_from_id(unsigned int id))(window_t*);
    void rainbow_rain(window_t *window);
    void blizzard(window_t *window);
    void bouncing_ball(window_t *window);
    void circus_circles(window_t *window);
    void building_windows(window_t *window);
    void rgb_tan(window_t *window);
    void random_numbers(window_t *window);
    void digital_clock(window_t *window);
    void zebra_horizon(window_t *window);
    void ten_print(window_t *window);
    void laser(window_t *window);
    void hamon(window_t *window);
    void lorenz_attractor(window_t *window);
    void bubble_sort_visualizer(window_t *window);
    void flowers(window_t *window);
#endif