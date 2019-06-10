/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** puts a nb
*/

#include <unistd.h>

void my_putfile(int nb, int fd)
{
    char c;

    if (nb > 10)
    my_putfile(nb / 10, fd);
    c = (nb % 10) + 48;
    write(fd, &c, 1);
}

void my_putnbr(int nb)
{
    char c;

    if (nb < 0){
    write(1, "-", 1);
    nb = nb * -1;
    }
    if (nb >= 10)
    my_putnbr(nb / 10);
    c = (nb % 10) + 48;
    write(1, &c, 1);
}