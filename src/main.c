/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** main
*/

#include "tetris.h"
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>

static struct option long_options[] =
    {
        {"level", required_argument, 0, 'L'},
        {"key-left=", required_argument, 0, 'l'},
        {"key-right=", required_argument, 0, 'r'},
        {"key-turn", required_argument, 0, 't'},
        {"key-drop", required_argument, 0, 'd'},
        {"key-quit", required_argument, 0, 'q'},
        {"key-pause", required_argument, 0, 'p'},
        {"map-size", required_argument, 0, 'm'},
        {"without-next", no_argument, 0, 'w'},
        {"debug", no_argument, 0, 'D'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
};

int main (int ac, char *av[])
{
    struct control control;
    init_struct(&control);
    int flag;
    while ((flag = getopt_long(ac, av, "L:l:r:t:d:p:q:wD",
    long_options, NULL)) != -1) {
        switch (flag) {
            case 'h' :
                help(av[0]);
                break;
            case 'L' :
                if (check_numbers(optarg) == 84)
                    return (84);
                control.level = atoi(optarg);
                break;
        }
        if (flager(&control, flag, av) == 84)
            return (84);
    }
    if (control.mode == 1)
        debug_mode(&control);
    else
        return (game_mode());
}

void help (char *av)
{
    my_putstr("Usage:  ");
    my_putstr(av);
    my_putstr(" [options]\n Options : \n");
    my_putstr("--help Display this help\n");
    my_putstr("-L --level={num} Start Tetris at level num (def: 1)\n");
    my_putstr("-l --key-left={K}    Move the tetrimino LEFT using the");
    my_putstr("K key (def: left arrow)\n");
    my_putstr("-r --key-right={K}   Move the tetrimino RIGHT using the");
    my_putstr("K key (def: right arrow)\n");
    my_putstr("-t --key-turn={K}    TURN the tetrimino clockwise 90d");
    my_putstr("using the K key (def: top arrow)\n");
    my_putstr("-d --key-drop={K}    DROP the tetrimino using the K");
    my_putstr("key (def: down arrow)\n");
    my_putstr("-q --key-quit={K} QUIT the game using \n");
    my_putstr("the K key(def:‘q’ key)\n");
    my_putstr("-p --key-pause={K}   PAUSE/RESTART the game using the");
    my_putstr("K key (def: space bar)\n");
    my_putstr("--map-size={row,col} Set the numbers of rows and columns");
    my_putstr("of the map (def: 20,10)\n");
    my_putstr("-w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr("-D --debug           Debug mode (def: false)\n");
}

int flager(struct control *control, int flag, char **av)
{
    switch (flag) {
            case 'm' :
                if (check_m(optarg, control) == 84)
                    return (84);
                break;
            case 'd' :
                control->drop = optarg;
                break;
            case '?':
                return (84);
                break;
            case 't' :
                control->turn = optarg;
                break;
            case 'w' :
                control->next = 1;
                break;
        }
    flager2(control, flag);
}

void flager2(struct control *control, int flag)
{
    int mode = 0;

    switch (flag) {
        case 'l' :
            control->left = optarg;
            break;
        case 'q' :
            control->quit = optarg;
            break;
        case 'p' :
            control->pause = optarg;
            break;
        case 'r' :
            control->right = optarg;
            break;
        case 'D' :
            control->mode = 1;
            break;
    }
}
