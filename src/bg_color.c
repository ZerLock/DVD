/*
** PERSONNAL PROJECT, 2021
** bg_color.c - DVD
** Contributors:
** @DUBOSCLARD LÉO && @Just1Truc
** File description:
** change the background color
*/

#include "header.h"

sfColor change_bg_color(sfVector2f dvd_pos, sfColor current)
{
    sfColor new_color;

    new_color = current;
    if (dvd_pos.x == 0)
        new_color = sfBlue;
    if (dvd_pos.y == 0)
        new_color = sfGreen;
    if (dvd_pos.x == WIDTH - WIDTH_DVD)
        new_color = sfBlack;
    if (dvd_pos.y == HEIGHT - HEIGHT_DVD)
        new_color = sfRed;
    return (new_color);
}
