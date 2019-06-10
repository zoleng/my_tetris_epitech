/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if (c == ' ')
        return (0);
    return (-1)
}

int check_line_1(char *str)
{
    int i = 0;
    int spaces = 0;

    for (;str[i] != '\n'; i++) {
        if (is_num(str[i] == -1))
            return (-1);
        else if (is_num(str[i] == 0))
            spaces++;
    }
    if (spaces != 2)
        return (-1);
    else
        return (1);
}

int find_cols(char *str)
{
    int cols;

    cols = str[0] - '0';
    return (cols);
}

int find_lines(char *str)
{
    int lines;

    lines = str[2] - '0';
    return (lines);
}

int count_cols(char *str)
{
    int tmp = 0;
    int cols = -1;

    for (int i = 7; str[i]; i++) {
        if (str[i] != '\n')
            tmp++;
        else {
            if (tmp >= cols)
                cols = tmp;
            tmp = 0;
        }
    }
    return (cols);
}

int count_lines(char *str)
{
    int lines = 0;
    
    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            lines++;
    return (lines);
}
