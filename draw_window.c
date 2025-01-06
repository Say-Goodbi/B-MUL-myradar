/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Draws everything
*/

#include "myradar.h"

void draw_chunk(game_t *game, chunk_t *chunk)
{
    if (!chunk || game->show_divides == false)
        return;
    sfRenderWindow_drawRectangleShape(game->win, chunk->rect, NULL);
    if (chunk->subchunks) {
        for (int i = 0; chunk->subchunks[i]; i++) {
            draw_chunk(game, chunk->subchunks[i]);
        }
    }
}

void draw_a_tower(game_t *game, tower_t *tower)
{
    if (game->entities_shown)
        sfRenderWindow_drawRectangleShape(game->win, tower->rectangle, NULL);
    sfRenderWindow_drawCircleShape(game->win, tower->circle, NULL);
}

void draw_a_plane(game_t *game, plane_t *plane)
{
    if (plane->state == FLYING) {
        sfRenderWindow_drawRectangleShape(game->win, plane->hitbox, NULL);
        if (game->entities_shown)
            sfRenderWindow_drawRectangleShape(game->win, plane->textbox, NULL);
    }
}

void draw_window(game_t *game)
{
    plane_t **planes = game->planes;
    tower_t **towers = game->towers;

    sfRenderWindow_clear(game->win, sfBlack);
    draw_chunk(game, game->original_chunk);
    if (towers) {
        for (int i = 0; towers[i] != NULL; i++) {
            draw_a_tower(game, towers[i]);
        }
    }
    for (int i = 0; planes[i] != NULL; i++) {
        draw_a_plane(game, planes[i]);
    }
    for (int i = 0; i < TEXTS_NB; i++)
        sfRenderWindow_drawText(game->win, game->texts[i].text, NULL);
    sfRenderWindow_display(game->win);
}
