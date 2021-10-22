/*
** PERSONNAL PROJECT, 2021
** header.h - DVD
** Contributors:
** @DUBOSCLARD LÉO && @Just1Truc
** File description:
** contain all prototypes of all functions
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #include <SFML/Graphics.h>
    #include "constants.h"

int x_calculate(int x, int val2add);
int y_calculate(int y, int val2add);
sfColor change_bg_color(sfVector2f dvd_pos, sfColor current);
void move_dvd(sfVector2f *dvd_pos, int dvd_po_in[2], int val2add[2]);

#endif /* HEADER_H_ */
