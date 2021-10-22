/*
** PERSONNAL PROJECT, 2021
** movements.c - DVD
** Contributors:
** @DUBOSCLARD LÉO && @Just1Truc
** File description:
** Functions that move the sprite of the dvd.
*/

#include "constants.h"
#include "header.h"

void move_dvd(sfVector2f *dvd_pos, int dvd_po_in[2], int val2add[2])
{
    val2add[0] = x_calculate(dvd_po_in[0], val2add[0]);
    val2add[1] = y_calculate(dvd_po_in[1], val2add[1]);
    dvd_pos->x += val2add[0];
    dvd_pos->y += val2add[1];
    dvd_po_in[0] += val2add[0];
    dvd_po_in[1] += val2add[1];
}

int x_calculate(int x, int val2add)
{
    if (x >= WIDTH - WIDTH_DVD)
        return (-1);
    if (x <= 0)
        return (1);
    return (val2add);
}

int y_calculate(int y, int val2add)
{
    if (y >= HEIGHT - HEIGHT_DVD)
        return (-1);
    if (y <= 0)
        return (1);
    return (val2add);
}
