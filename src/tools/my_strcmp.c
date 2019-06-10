/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare two strings
*/

int my_strcmp(char *tocmp, char *model)
{
    for (int i = 0; model[i] != 0; i++)
        if (tocmp[i] != model[i])
            return (0);
    return (1);
}
