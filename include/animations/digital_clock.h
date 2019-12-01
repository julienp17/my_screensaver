/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for clock animation
*/

#ifndef DISPLAY_CLOCK_H_
    #define DISPLAY_CLOCK_H_

    #include "window.h"

    #define FONT_SIZE               18
    #define REUNION_GMT             4
    #define DELAY                   1000

    typedef struct my_time {
        unsigned int hours;
        unsigned int minutes;
        unsigned int seconds;
    } my_time_t;

    my_time_t *init_my_time(void);
    my_time_t *get_current_time(int gmt);
    void update_time(my_time_t *current_time);

    void display_clock(window_t *window);
#endif