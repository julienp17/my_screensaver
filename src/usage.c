/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Print usage information about my_screensaver
*/

#include <stdbool.h>
#include "my_screensaver.h"
#include "my.h"

int check_args(int ac, char **av)
{
    if (ac != 2) {
        my_puterr(av[0]);
        my_puterr(": bad arguments: ");
        my_puterr(my_int_to_strnum(ac - 1));
        my_puterr(" given but 1 is required\n");
        my_puterr("retry with -h\n");
        return (MY_EXIT_FAILURE);
    }
    if (is_option(av[1])) {
        print_help();
        return (MY_EXIT_OPTION);
    }
    if (!my_str_isnum_pos(av[1])) {
        my_puterr("Given argument is not a positive number.");
        print_usage();
        return (MY_EXIT_FAILURE);
    }
    return (MY_EXIT_SUCCESS);
}

bool is_option(char *str)
{
    if (my_strcmp(str, "-h") == 0 || my_strcmp(str, "--help") == 0)
        return (true);
    return (false);
}

void print_help(void)
{
    my_putstr(SHORT_PROGRAM_DESCRIPTION);
    my_putchar('\n');
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
    my_putstr("(between ? and ?).");
    my_putchar('\n');
}

void print_options(void)
{
    my_putstr("OPTIONS\n");
    my_putstr("  -d               print the description of all the animations");
    my_putstr(" and quit.\n");
    my_putstr("  -h               print the usage and quit.\n");
}