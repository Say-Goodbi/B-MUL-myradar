/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** Takes in events.
*/

#include <SFML/Graphics.h>

void analyse_events(sfEvent event, sfRenderWindow *win)
{
    sfEventType type = event.type;

    switch (type) {
        case sfEvtClosed :
            return close_window(win);
    }
}
