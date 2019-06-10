/*
** EPITECH PROJECT, 2019
** e
** File description:
** i
*/

#include "tetris.h"

int check_letters(char *str)
{
    for (int i = 0; i != my_strlen(str); i++) {
    }
}

int check_numbers (char *str)
{
    for (int i = 0; i != my_strlen(str); i++) {
        if (str[i] > 57 || str[i] < 48 && str[i] != ',') {
            my_putstr("ERROR : Check your params\n");
            return (84);
        }
    }
    return (0);
}

int check_m (char *optarg, struct control *control)
{
    int i = 0;
    int j = my_strlen(optarg);

    if (check_numbers(optarg) == 84)
                return (84);
    while (optarg[i] != ',') {
        control->map_row = optarg[i] - 48;
        i++;
    }
    while (i != j) {
        control->map_col = optarg[i] - 48;
        i++;
    }
}
