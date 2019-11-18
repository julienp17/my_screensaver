/*
** EPITECH PROJECT, 2019
** Libmy
** File description:
** Compares two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    unsigned int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i = i + 1;
    return (s1[i] - s2[i]);
}