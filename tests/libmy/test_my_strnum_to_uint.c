/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Unit tests for my_strnum_to_uint
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strnum_to_uint, basic_usage)
{
    char const strnum[] = "123456789";
    unsigned int actual = 0;
    unsigned int expected = 123456789;

    actual = my_strnum_to_uint(strnum);
    cr_assert_eq(actual, expected);
}

Test(my_strnum_to_uint, one_zero_in_strnum)
{
    char const strnum[] = "0";
    unsigned int actual = 0;
    unsigned int expected = 0;

    actual = my_strnum_to_uint(strnum);
    cr_assert_eq(actual, expected);
}

Test(my_strnum_to_uint, multiple_zero_in_strnum)
{
    char const strnum[] = "00000000";
    unsigned int actual = 0;
    unsigned int expected = 0;

    actual = my_strnum_to_uint(strnum);
    cr_assert_eq(actual, expected);
}

Test(my_strnum_to_uint, greater_than_uintmax_len)
{
    char const strnum[] = "829648184896189466186489648968496";
    unsigned int actual = 0;
    unsigned int expected = 0;

    actual = my_strnum_to_uint(strnum);
    cr_assert_eq(actual, expected);
}

Test(my_strnum_to_uint, greater_than_uintmax_value)
{
    char const strnum[] = "4294967296";
    unsigned int actual = 0;
    unsigned int expected = 0;

    actual = my_strnum_to_uint(strnum);
    cr_assert_eq(actual, expected);
}