/*
** PERSONNAL PROJECT, 2021
** movements.c - DVD
** Contributors:
** @DUBOSCLARD LÉO && @Just1Truc
** File description:
** Functions that move the sprite of the dvd.
*/

#include "movements.h"

int x_calculate(int x, int width, int val2add)
{
    if (x >= width - 270)
        return (-1);
    if (x <= -30)
        return (1);
    return (val2add);
}

int y_calculate(int y, int height, int val2add)
{
    if (y >= height - 200)
        return (-1);
    if (y <= -50)
        return (1);
    return (val2add);
}
