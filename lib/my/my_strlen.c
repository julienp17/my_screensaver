/*
** EPITECH PROJECT, 2019
** My screensaver
** File description:
** Returns the number of characters in a string
*/

unsigned int my_strlen(char const *str)
{
    int len = 0;

    while (str[len])
        len++;
    return (len);
}