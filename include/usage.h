/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Header file for my screensaver
*/

#ifndef USAGE_H_
    #define USAGE_H_

    #define MY_EXIT_SUCCESS             0
    #define MY_EXIT_FAILURE             84
    #define MY_EXIT_OPTION              92

    #define SHORT_PROGRAM_DESCRIPTION   \
            "animation rendering in a CSFML window.\n"

    int check_args(int ac, char **av);
    int check_options(char *arg);

    void print_help(void);
    void print_usage(void);
    void print_options(void);
    void print_animations_descriptions(void);
#endif