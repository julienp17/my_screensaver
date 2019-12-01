/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Functions to print usage
*/

#include "usage.h"
#include "animations.h"
#include "my.h"

void print_help(void)
{
    my_putstr(SHORT_PROGRAM_DESCRIPTION);
    my_putchar('\n');
    print_usage();
    my_putchar('\n');
    print_options();
}

void print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("  ./my_screensaver [OPTIONS] animation_id\n");
    my_putstr("    animation_id   ID of the animation to process ");
    my_putstr("(between 1 and ");
    my_putstr(my_int_to_strnum(MAX_ID));
    my_putstr(").\n");
}

void print_options(void)
{
    my_putstr("OPTIONS\n");
    my_putstr("  -d | --description              ");
    my_putstr("print the description of all the animations");
    my_putstr(" and quit.\n");
    my_putstr("  -h | --help                     print the usage and quit.\n");
    my_putstr("  -r | --random                   randomly select an ");
    my_putstr("animation.\n");
}

void print_animations_descriptions(void)
{
    char const *descriptions[] = {
        BLIZZARD_DESCRIPTION, CIRCUS_CIRCLES_DESCRIPTION,
        RAINBOW_RAIN_DESCRIPTION, FLOWERS_DESCRIPTION,
        LORENZ_ATTRACTOR_DESCRIPTION, HAMON_DESCRIPTION,
        LASER_DESCRIPTION, RANDOM_NUMBERS_DESCRIPTION,
        DIGITAL_CLOCK_DESCRIPTION, TEN_PRINT_DESCRIPTION,
        ZEBRA_HORIZON_DESCRIPTION, BUILDING_WINDOWS_DESCRIPTION,
        BOUNCING_BALL_DESCRIPTION, RGB_TAN_DESCRIPTION,
        BUBBLE_SORT_VISUALIZER_DESCRIPTION,
        NULL};

    for (unsigned int i = 0 ; descriptions[i] ; i++) {
        my_putstr(descriptions[i]);
        my_putchar('\n');
    }
}