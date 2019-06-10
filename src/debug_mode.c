/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** debug_mode
*/

#include "tetris.h"

int debug_mode (struct control *control)
{
    my_putstr("*** DEBUG MODE ***\n");
    my_putstr("Key Left : ");
    my_putstr(control->left);
    my_putchar('\n');
    my_putstr("Key Right : ");
    my_putstr(control->right);
    my_putchar('\n');
    my_putstr("Key Turn : ");
    my_putstr(control->turn);
    my_putchar('\n');
    my_putstr("Key Drop : ");
    my_putstr(control->drop);
    my_putchar('\n');
    my_putstr("Key Quit : ");
    my_putstr(control->quit);
    my_putchar('\n');
    my_putstr("Key Pause : ");
    my_putstr(control->pause);
    my_putchar('\n');
    debug_mode2(control);
}

int debug_mode2(struct control *control)
{
    my_putstr("Next : ");
    if (control->next == 1)
        my_putstr("Yes\n");
    else
        my_putstr("No\n");
    my_putstr("Level : ");
    my_putnbr(control->level);
    my_putchar('\n');
    my_putstr("Size : ");
    my_putnbr(control->map_row);
    my_putchar('*');
    my_putnbr(control->map_col);
    my_putchar('\n');
}
