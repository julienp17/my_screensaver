/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for clock animation
*/

#ifndef DISPLAY_CLOCK_H_
    #define DISPLAY_CLOCK_H_

    #include "window.h"

    #define FONT_SIZE     10

    typedef struct my_time {
        unsigned int hours;
        unsigned int minutes;
        unsigned int seconds;
    } my_time_t;

    my_time_t *init_my_time(void);
    my_time_t *get_current_time(int gmt);
    void update_time(my_time_t *current_time);

    void display_clock(window_t *window);

    void draw_digital_clock(window_t *window, my_time_t const *current_time,
                            sfVector2f pos, unsigned int size);
    void draw_digital_time_unit(window_t *window, unsigned int time_unit,
                                sfVector2f pos, unsigned int size);
    void draw_colon(window_t *window, sfVector2f pos, unsigned int size,
                    sfColor color);
#endif