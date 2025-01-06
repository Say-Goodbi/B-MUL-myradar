/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** My radar
*/

#include "myradar.h"

void interact_divide_visibility(game_t *game)
{
    if (game->show_divides == false) {
        game->show_divides = true;
    } else {
        game->show_divides = false;
    }
}
