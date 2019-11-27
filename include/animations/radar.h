/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for radar
*/

#ifndef RADAR_H_
    #define RADAR_H_

    #include <stdbool.h>
    #include "window.h"
    #include "shapes.h"

    #define LINES_OPACITY       255
    #define DEEP_SKY_BLUE4      0, 95, 175
    #define DEEP_PINK4          95, 0, 95
    #define DARK_ORANGE         255, 135, 0
    #define DARK_GREEN          0, 150, 0

    bool update_lines_step_1(window_t *window, line_t *line1, line_t *line2);
#endif