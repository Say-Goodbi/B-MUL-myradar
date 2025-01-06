/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Print FPS
*/

#include "myradar.h"

void fps_to_string(int fps, sfText *text)
{
    char *buff = my_strndup(sfText_getString(text), 8);

    if (fps > MAX_FRAMERATE)
        fps = MAX_FRAMERATE;
    if (fps > 1000)
        fps = 999;
    buff[0] = fps / 100 + 48;
    fps -= fps / 100 * 100;
    buff[1] = fps / 10 + 48;
    fps -= fps / 10 * 10;
    buff[2] = fps + 48;
    sfText_setString(text, buff);
    free(buff);
}

void print_framerate(game_t *game)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    sfTime elapsed = {0};

    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        fps_to_string(fps, game->texts[0].text);
        fps = 0;
        sfClock_restart(clock);
        game->seconds += (int)sfTime_asSeconds(elapsed);
    } else {
        fps++;
    }
}
