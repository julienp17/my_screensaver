/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for random
*/

#ifndef RANDOM_H_
    #define RANDOM_H_

    int get_random_int(float const min, float const max);
    float get_random_float(float const min, float const max);
    int get_random_choice_int(int choice1, int choice2);
    sfColor get_random_color(unsigned int opacity);
    sfColor get_black_or_white(void);
#endif