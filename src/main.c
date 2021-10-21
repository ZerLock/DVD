/*
** PERSONNAL PROJECT, 2021
** main.c - DVD
** Contributors:
** @DUBOSCLARD LÉO && @Just1Truc
** File description:
** main file with main function
*/

#include <SFML/Graphics.h>
#include "constants.h"
#include "movements.h"

sfVector2f get_position(sfVector2f *point_to)
{
     sfVector2f new_pos;
     new_pos.x = point_to->x;
     new_pos.y = point_to->y;
     return (new_pos);
}

int main(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *dvd;
    sfSprite *dvd_s;
    sfVector2f dvd_pos = {0, 0};
    int dvd_po_in[] = {0, 0};
    int val2add[] = {1, 1};
    sfColor black = sfBlack;
    sfColor red = sfRed;
    sfColor blue = sfBlue;
    sfColor green = sfGreen;
    sfColor current = sfBlack;

    dvd = sfTexture_createFromFile("obj/dvd_texture.png", NULL);
    dvd_s = sfSprite_create();
    sfSprite_setTexture(dvd_s, dvd, sfTrue);
    window = sfRenderWindow_create(mode, "DVD", sfClose, NULL);
    if (!window)
        return (84);
    sfWindow_setFramerateLimit((sfWindow *) window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        if (dvd_pos.x == 0)
            current = blue;
        if (dvd_pos.y == 0)
            current = green;
        if (dvd_pos.x == WIDTH - WIDTH_DVD)
            current = black;
        if (dvd_pos.y == HEIGHT - HEIGHT_DVD)
            current = red;
        sfRenderWindow_clear(window, current);
        val2add[0] = x_calculate(dvd_po_in[0], val2add[0]);
        val2add[1] = y_calculate(dvd_po_in[1], val2add[1]);
        dvd_pos.x += val2add[0];
        dvd_pos.y += val2add[1];
        dvd_po_in[0] += val2add[0];
        dvd_po_in[1] += val2add[1];
        sfSprite_setPosition(dvd_s, dvd_pos);
        sfRenderWindow_drawSprite(window, dvd_s, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(dvd);
    sfSprite_destroy(dvd_s);
    sfRenderWindow_destroy(window);
    return (0);
}
