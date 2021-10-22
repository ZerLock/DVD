/*
** PERSONNAL PROJECT, 2021
** main.c - DVD
** Contributors:
** @DUBOSCLARD LÉO && @Just1Truc
** File description:
** main file with main function
*/

#include "header.h"

sfVector2f get_position(sfVector2f *point_to)
{
     sfVector2f new_pos;
     new_pos.x = point_to->x;
     new_pos.y = point_to->y;
     return (new_pos);
}

void get_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void game_loop(sfRenderWindow *window)
{
    sfEvent event;
    sfColor current = sfBlack;
    sfTexture *dvd = sfTexture_createFromFile("obj/dvd_texture.png", NULL);
    sfSprite *dvd_s = sfSprite_create();
    sfVector2f dvd_pos = {0, 0};
    int dvd_po_in[] = {0, 0};
    int val2add[] = {1, 1};
    
    sfSprite_setTexture(dvd_s, dvd, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while(sfRenderWindow_pollEvent(window, &event))
            get_event(window, event);
        current = change_bg_color(dvd_pos, current);
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
    sfSprite_destroy(dvd_s);
    sfTexture_destroy(dvd);
}

int main(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window;
    
    window = sfRenderWindow_create(mode, "DVD", sfClose, NULL);
    if (!window)
        return (84);
    sfWindow_setFramerateLimit((sfWindow *) window, 60);
    game_loop(window);
    sfRenderWindow_destroy(window);
    return (0);
}
