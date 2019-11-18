/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Unit tests for my_strcmp
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strcmp, basic_usage_eq)
{
    char const s1[] = "hello";
    char const s2[] = "hello";
    int actual = 0;
    int expected = 0;

    actual = my_strcmp(s1, s2);
    cr_assert_eq(actual, expected);
}

Test(my_strcmp, basic_usage_neq_same_len)
{
    char const s1[] = "halo";
    char const s2[] = "hola";
    int actual = 0;
    int expected = -14;

    actual = my_strcmp(s1, s2);
    cr_assert_eq(actual, expected);
}

Test(my_strcmp, same_beg_len1_gt)
{
    char const s1[] = "hol horse";
    char const s2[] = "hol";
    int actual = 0;
    int expected = 32;

    actual = my_strcmp(s1, s2);
    cr_assert_eq(actual, expected);
}

Test(my_strcmp, same_beg_len2_gt)
{
    char const s1[] = "whole";
    char const s2[] = "whole horse";
    int actual = 0;
    int expected = -32;

    actual = my_strcmp(s1, s2);
    cr_assert_eq(actual, expected);
}