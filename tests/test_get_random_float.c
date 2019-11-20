/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Unit tests for get_random_float
*/

#include <criterion/criterion.h>

float get_random_float(float const min, float const max);

Test(get_random_float, zero_one)
{
    float actual = 0.0;
    float const min = 0.0;
    float const max = 1.0;

    actual = get_random_float(min, max);
    cr_assert(actual >= min && actual <= max);
}

Test(get_random_float, zero_ten)
{
    float actual = 0.0;
    float const min = 0.0;
    float const max = 10.0;

    actual = get_random_float(min, max);
    cr_assert(actual >= min && actual <= max);
}

Test(get_random_float, zero_one_hundred)
{
    float actual = 0.0;
    float const min = 0.0;
    float const max = 100.0;

    actual = get_random_float(min, max);
    cr_assert(actual >= min && actual <= max);
}

Test(get_random_float, fifty_one_hundred)
{
    float actual = 0.0;
    float const min = 50.0;
    float const max = 100.0;

    actual = get_random_float(min, max);
    cr_assert(actual >= min && actual <= max);
}

Test(get_random_float, neg_four_neg_two)
{
    float actual = 0.0;
    float const min = -4.0;
    float const max = -2.0;

    actual = get_random_float(min, max);
    cr_assert(actual >= min && actual <= max);
}

Test(get_random_float, neg_four_two)
{
    float actual = 0.0;
    float const min = -4.0;
    float const max = 2.0;

    actual = get_random_float(min, max);
    cr_assert(actual >= min && actual <= max);
}

Test(get_random_float, min_gt_max)
{
    float actual = 0.0;
    float const min = 6.0;
    float const max = 5.0;

    actual = get_random_float(min, max);
    cr_assert_eq(actual, 0.0);
}

Test(get_random_float, min_eq_max)
{
    float actual = 0.0;
    float const min = 5.0;
    float const max = 5.0;

    actual = get_random_float(min, max);
    cr_assert_eq(actual, 5.0);
}