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
    sfTexture *dvd;
    sfSprite *dvd_s;
    sfVector2f dvd_pos = {WIDTH / 2 - WIDTH_DVD / 2, HEIGHT / 2 - HEIGHT_DVD / 2};

    dvd = sfTexture_createFromFile("obj/dvd.png", NULL);
    dvd_s = sfSprite_create();
    sfSprite_setTexture(dvd_s, dvd, sfFalse);
    window = sfRenderWindow_create(mode, title, sfClose, NULL);
    if (!window)
        return (84);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfWhite);
        sfSprite_setPosition(dvd_s, dvd_pos);
        sfRenderWindow_drawSprite(window, dvd_s, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(dvd);
    sfSprite_destroy(dvd_s);
    sfRenderWindow_destroy(window);
    return (0);
}
