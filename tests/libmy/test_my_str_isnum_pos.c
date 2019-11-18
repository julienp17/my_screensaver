/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Unit tests for my_str_isnum_pos
*/

#include <stdbool.h>
#include <criterion/criterion.h>
#include "my.h"

Test(my_str_isnum_pos, basic_usage_true)
{
    char const str[] = "0123456789";
    bool actual = false;
    bool expected = true;

    actual = my_str_isnum_pos(str);
    cr_assert_eq(actual, expected);
}

Test(my_str_isnum_pos, basic_usage_false)
{
    char const str[] = "alpha";
    bool actual = false;
    bool expected = false;

    actual = my_str_isnum_pos(str);
    cr_assert_eq(actual, expected);
}

Test(my_str_isnum_pos, neg_strnum)
{
    char const str[] = "-84";
    bool actual = false;
    bool expected = false;

    actual = my_str_isnum_pos(str);
    cr_assert_eq(actual, expected);
}