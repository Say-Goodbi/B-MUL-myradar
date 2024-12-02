/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** Planes go zeeeeeee
*/

#include <SFML/Graphics.h>

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circ = sfCircleShape_create();
    sfColor color = sfWhite;
    sfColor transp = sfTransparent;

    sfCircleShape_setPosition(circ, position);
    sfCircleShape_setOutlineThickness(circ, 1);
    sfCircleShape_setOutlineColor(circ, color);
    sfCircleShape_setFillColor(circ, transp);
    sfCircleShape_setRadius(circ, radius);
    return circ;
}

float square(float nb)
{
    return nb * nb;
}

int circles_collide(sfCircleShape *circ1, sfCircleShape *circ2)
{
    sfVector2f pos1 = sfCircleShape_getPosition(circ1);
    sfVector2f pos2 = sfCircleShape_getPosition(circ2);
    float r1 = sfCircleShape_getRadius(circ1);
    float r2 = sfCircleShape_getRadius(circ2);

    if (square(pos1.x - pos2.x) + square(pos1.y - pos2.y) > r1 + r2) {
        return 1; 
    }
    return 0;
}

void fill_colors(sfCircleShape *circ1, sfCircleShape *circ2)
{
    sfCircleShape_setFillColor(circ1, sfWhite);
    sfCircleShape_setFillColor(circ2, sfWhite);
}

int main()
{
    sfVideoMode mode = {800, 1000, 32};
    sfRenderWindow *win = sfRenderWindow_create(mode, "My Radar", sfResize | sfClose, NULL);
    sfCircleShape *circ1 = create_circle((sfVector2f){300, 300}, 100.0f);
    sfCircleShape *circ2 = create_circle((sfVector2f){600, 500}, 70.0f);
    sfEvent event;

    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &event)) {
            analyse_events(event, win);
        }

        if (circles_collide(circ1, circ2) == 1)
            fill_colors(circ1, circ2);
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawCircleShape(win, circ1, NULL);
        sfRenderWindow_drawCircleShape(win, circ2, NULL);
        sfRenderWindow_display(win);
    }
    sfRenderWindow_destroy(win);
    sfCircleShape_destroy(circ1);
    sfCircleShape_destroy(circ2);
}
