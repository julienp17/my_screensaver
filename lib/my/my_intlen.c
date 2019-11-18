/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Returns the number of digits in an integer
*/

unsigned int my_intlen(int nb)
{
    unsigned int len = 0;

    if (nb == 0)
        return (1);
    while (nb != 0) {
        len++;
        nb /= 10;
    }
    return (len);
}