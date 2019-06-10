/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <curses.h>
#include <stdlib.h>
#include "../../include/structs.h"

void print_score(int score, int time)
{
    char time_str[50];
    char score_str[50];

    sprintf(time_str, "%i", time);
    sprintf(score_str, "%i", score);
    mvaddstr(12, 10, "+-------------+");
    mvaddstr(13, 10, "|             |");
    mvaddstr(14, 10, "|Score:       |");
    mvaddstr(14, 18, score_str);
    mvaddstr(15, 10, "|             |");
    mvaddstr(16, 10, "|Time:        |");
    mvaddstr(16, 18, time_str);
    mvaddstr(17, 10, "+-------------+");
}

void print_tetris(void)
{
    mvaddstr(8, 10, "  ____  ____  ____  ____  __  ____");
    mvaddstr(9, 10, " (_  _)(  __)(_  _)(  _ )(  )/ ___)");
    mvaddstr(10, 10, "  )(   ) _)   )(   )  /  )( \___ )");
    mvaddstr(11, 10, " (__) (____) (__) (__\_)(__)(____/");
}

void print_walls(void)
{
    mvaddstr(12, 25, "+--------------------------------------+");
    for (int i = 13; i < 38; i++)
        mvaddstr(i, 25, "|                                      |");
    mvaddstr(38, 25, "+--------------------------------------+");
}

void print_ui(int score, int timer)
{
    print_tetris();
    print_walls();
    print_score(score, timer / 10);
}

WINDOW *window_setup(void)
{
    WINDOW *mainwin;

    mainwin = initscr();
    if (mainwin == NULL)
	exit(84);
    noecho();
    curs_set(FALSE);
    nodelay(mainwin, TRUE);
    cbreak();
    keypad(mainwin, TRUE);
    return (mainwin);
}
