/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** init_struct
*/

#include "tetris.h"

void init_struct (struct control *control)
{
    control->level = 1;
    control->left = "^EOD";
    control->right = "^EOC";
    control->turn = "^EOA";
    control->drop = "^EOB";
    control->quit = "q";
    control->pause = "p";
    control->map_row = 20;
    control->map_col = 10;
    control->next = 1;
    control->mode = 0;
}