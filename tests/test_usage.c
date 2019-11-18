/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Unit tests for printing usage information
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_screensaver.h"

Test(check_args, bad_ac_1, .init = cr_redirect_stderr)
{
    int ac = 1;
    char *av[] = {"./my_screensaver", "-h", "too_much"};
    char expected[] = "./my_screensaver: bad arguments: 0 given but 1 is "
    "required\nretry with -h\n";

    check_args(ac, av);
    cr_assert_stderr_eq_str(expected);
}

Test(check_args, bad_ac_3, .init = cr_redirect_stderr)
{
    int ac = 3;
    char *av[] = {"./my_screensaver", "-h", "too_much"};
    char expected[] = "./my_screensaver: bad arguments: 2 given but 1 is "
    "required\nretry with -h\n";

    check_args(ac, av);
    cr_assert_stderr_eq_str(expected);
}

Test(is_option, true_h, .init = cr_redirect_stdout)
{
    char *str = "-h";
    bool actual = false;
    bool expected = true;

    actual = is_option(str);
    cr_assert_eq(actual, expected);
}

Test(is_option, true_help, .init = cr_redirect_stdout)
{
    char *str = "--help";
    bool actual = false;
    bool expected = true;

    actual = is_option(str);
    cr_assert_eq(actual, expected);
}

Test(is_option, false_option, .init = cr_redirect_stdout)
{
    char *str = "-v";
    bool actual = false;
    bool expected = false;

    actual = is_option(str);
    cr_assert_eq(actual, expected);
}

Test(is_option, false_number, .init = cr_redirect_stdout)
{
    char *str = "5";
    bool actual = false;
    bool expected = false;

    actual = is_option(str);
    cr_assert_eq(actual, expected);
}