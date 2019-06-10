/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/
#include <curses.h>
#include <stdlib.h> 
#include "../include/structs.h"

void draw_tetromino(shape tetromino)
{
    mvaddstr(tetromino.x, tetromino.y, tetromino.shape);
}

int get_inputs(void)
{
    int ch = getch();
    
    if (ch == KEY_LEFT)  /* user pressed up arrow key */
        return (1);
    else if (ch == KEY_RIGHT)  /* user pressed up arrow key */
        return (2);
    else if (ch == KEY_DOWN)
        return (3);
    else 
        return (0);
}

shape refresh_game(int timer, shape tetromino)
{
    int mov = get_inputs();

    if (timer % 100 == 0)
        tetromino.x += 1;
    if (mov == 1 && tetromino.y > 26)
        tetromino.y += -1;
    else if (mov == 2 && tetromino.y < 60)
        tetromino.y += 1;
    else if (mov == 3)
        tetromino.x += 1;
    draw_tetromino(tetromino);
    return (tetromino);
}

int game_mode(void)
{
    WINDOW * mainwin;
    shape tetromino;

    tetromino.shape = "++++";
    tetromino.x = 13;
    tetromino.y = 30;
    mainwin = window_setup();
    for (int i = 0; i < 100000000; i++) {
        werase(mainwin);
        print_ui(20, i);
        tetromino = refresh_game(i, tetromino);
        refresh();
        usleep(5000);
    }
    delwin(mainwin);
    endwin();
    return (0);    
}
