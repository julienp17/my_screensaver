/*
** EPITECH PROJECT, 2019
** My Screensaver
** File description:
** Displays a grid of black and white squares
*/

#include <stdlib.h>
#include <SFML/System/Time.h>
#include "game_of_life.h"
#include "window.h"
#include "square.h"
#include "random.h"

int **create_board(window_t *window);

void game_of_life(window_t *window)
{
    int **board = create_board(window);
    (void)board;

    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        window_refresh(window, &sfBlack);
    }
}

int **create_board(window_t *window)
{
    int **board = malloc(sizeof(int *) * (window->height / 10));

    return (board);
}