/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}