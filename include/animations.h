/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Header file for animations
*/

#ifndef ANIMATIONS_H_
    #define ANIMATIONS_H_

    #include "window.h"

    void (*get_animation_from_id(unsigned int nb))(window_t*);
    void purple_rain(window_t *window);
#endif