/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Print usage information about my_screensaver
*/

#include <stdbool.h>
#include "usage.h"
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
    if (check_options(av[1]) == MY_EXIT_SUCCESS)
        return (MY_EXIT_OPTION);
    if (my_strcmp(av[1], "-r") == 0 || my_strcmp(av[1], "--random") == 0)
        return (MY_EXIT_SUCCESS);
    if (!my_str_isnum_pos(av[1])) {
        my_puterr("Given argument is not a positive number.\n");
        print_usage();
        return (MY_EXIT_FAILURE);
    }
    return (MY_EXIT_SUCCESS);
}

int check_options(char *arg)
{
    if (my_strcmp(arg, "-h") == 0 || my_strcmp(arg, "--help") == 0) {
        print_help();
        return (MY_EXIT_SUCCESS);
    }
    if (my_strcmp(arg, "-d") == 0 || my_strcmp(arg, "--description") == 0) {
        print_animations_descriptions();
        return (MY_EXIT_SUCCESS);
    }
    return (MY_EXIT_FAILURE);
}