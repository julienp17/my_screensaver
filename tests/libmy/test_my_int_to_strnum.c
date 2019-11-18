/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Unit test for my_int_to_strnum.c
*/

#include <stddef.h>
#include <limits.h>
#include <criterion/criterion.h>
#include "my.h"

Test(my_int_to_strnum, zero)
{
    int nb = 0;
    char *actual = NULL;
    char const expected[] = "0";

    actual = my_int_to_strnum(nb);
    cr_assert_str_eq(actual, expected);
}

Test(my_int_to_strnum, fourty_two)
{
    int nb = 42;
    char *actual = NULL;
    char const expected[] = "42";

    actual = my_int_to_strnum(nb);
    cr_assert_str_eq(actual, expected);
}

Test(my_int_to_strnum, neg_eighty_four)
{
    int nb = -84;
    char *actual = NULL;
    char const expected[] = "-84";

    actual = my_int_to_strnum(nb);
    cr_assert_str_eq(actual, expected);
}

Test(my_int_to_strnum, int_min)
{
    int nb = INT_MIN;
    char *actual = NULL;
    char const expected[] = "-2147483648";

    actual = my_int_to_strnum(nb);
    cr_assert_str_eq(actual, expected);
}

Test(my_int_to_strnum, int_max)
{
    int nb = INT_MAX;
    char *actual = NULL;
    char const expected[] = "2147483647";

    actual = my_int_to_strnum(nb);
    cr_assert_str_eq(actual, expected);
}