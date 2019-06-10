/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

typedef struct control control;
struct control
{
    int level;
    char *left;
    char *right;
    char *turn;
    char *drop;
    char *quit;
    char *pause;
    int map_row;
    int next;
    int map_col;
    int mode;
};

void help (char *av);
int flager(struct control *control, int flag, char **av);
void flager2(struct control *control, int flag);

int my_putstr(char *str);
void my_putchar(char c);

void init_struct(struct control *control);

int debug_mode (struct control *control);
int debug_mode2(struct control *control);

int game_mode (void);

int my_strlen(char const *str);

int check_numbers(char *str);
int check_m (char *optarg, struct control *control);

int my_strcmp(char *tocmp, char *model);

void my_putnbr(int nb);
void my_putfile(int nb, int fd);

#endif /* !TETRIS_H_ */
