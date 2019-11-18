/*
** EPITECH PROJECT, 2019
** My ScreenSaver
** File description:
** Unit tests for my_strlen
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strlen, basic_usage)
{
    char const str[] = "hello";
    unsigned int actual = 0;
    unsigned int expected = 5;

    actual = my_strlen(str);
    cr_assert_eq(actual, expected);
}

Test(my_strlen, empty_str)
{
    char const str[] = "";
    unsigned int actual = 0;
    unsigned int expected = 0;

    actual = my_strlen(str);
    cr_assert_eq(actual, expected);
}