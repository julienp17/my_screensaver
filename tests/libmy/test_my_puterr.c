/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Unit tests for my_puterr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_puterr, basic_usage, .init = cr_redirect_stderr)
{
    char const err_msg[] = "error";
    char const expected[] = "error";

    my_puterr(err_msg);
    cr_assert_stderr_eq_str(expected);
}