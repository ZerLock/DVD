/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "constants.h"

int main(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window;
    char *title = "DVD";
    sfEvent event;

    window = sfRenderWindow_create(mode, title, sfClose, NULL);
    if (!window)
        return (84);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_display(window);
        }
    }
    sfRenderWindow_destroy(window);
    return (0);
}
