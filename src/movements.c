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
