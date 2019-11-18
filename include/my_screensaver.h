/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Header file for my screensaver
*/

#ifndef MY_SCREENSAVER_H_
    #define MY_SCREENSAVER_H_

    #include <stdbool.h>
    #include "framebuffer.h"

    #define MY_EXIT_SUCCESS             0
    #define MY_EXIT_FAILURE             84
    #define MY_EXIT_OPTION              92

    #define SHORT_PROGRAM_DESCRIPTION   "animation rendering in a CSFML window."

    int check_args(int ac, char **av);
    void print_help(void);
    void print_usage(void);
    void print_options(void);
    bool check_option(char *str);

    void display_screensaver(void (*play_animation)(framebuffer_t*));
#endif