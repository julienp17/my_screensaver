/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Utilities files for my_time
*/

#include <stdlib.h>
#include <time.h>
#include "digital_clock.h"

my_time_t *init_my_time(void)
{
    my_time_t *my_time = malloc(sizeof(*my_time));

    my_time->hours = 0;
    my_time->minutes = 0;
    my_time->seconds = 0;
    return (my_time);
}

my_time_t *get_current_time(int gmt)
{
    my_time_t *my_time = init_my_time();
    time_t current_time;

    time(&current_time);
    while (current_time > 86400)
        current_time -= 86400;
    while (current_time > 3600) {
        my_time->hours++;
        current_time -= 3600;
    }
    my_time->hours += gmt;
    while (current_time > 60) {
        my_time->minutes++;
        current_time -= 60;
    }
    my_time->seconds = current_time;
    return (my_time);
}

void update_time(my_time_t *current_time)
{
    current_time->seconds++;
    if (current_time->seconds >= 60) {
        current_time->minutes++;
        current_time->seconds = 0;
    }
    if (current_time->minutes >= 60) {
        current_time->hours++;
        current_time->minutes = 0;
    }
    if (current_time->hours >= 24)
        current_time->hours = 0;
}