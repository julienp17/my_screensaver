/*
** EPITECH PROJECT, 2019
** Libmy
** File description:
** Header file for my library
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdbool.h>

    #define UNSIGNED_INT_MAX_LEN        10
    #define UNSIGNED_INT_MAX_STR        "4294967295"

    void my_putchar(char c);
    void my_putstr(char const *str);
    void my_puterr(char const *err_msg);

    bool my_str_isnum_pos(char const *str);

    int my_strcmp(char const *s1, char const *s2);
    unsigned int my_intlen(int nb);
    unsigned int my_strlen(char const *str);
    unsigned int my_strnum_to_uint(char const *strnum);

    char *my_int_to_strnum(int nb);
    char *my_revstr(char *str);
#endif