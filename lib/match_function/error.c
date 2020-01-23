/*
** EPITECH PROJECT, 2020
** error.c
** File description:
** all player input error
*/

#include "../../include/matchstick.h"

int det_nb_line(char **tab, int line)
{
    int nb = 0;

    for (int i = 0; tab[line][i]; i += 1)
        if (tab[line][i] == '|')
            nb += 1;
    return (nb);
}

int check_minus(char *buffer)
{
    for (int i = 0; buffer[i] != '\n'; i += 1) {
        if (buffer[i] == '-' && i != 0)
            return (1);
    }
    return (0);
}

int error_line(char *buffer, int line)
{
    int i = 0;

    if (!buffer)
        return (1);
    if (my_str_isnum(buffer) == 1 || check_minus(buffer) == 1) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (1);
    }
    i = my_getnbr(buffer);
    if (i <= 0 || i > line) {
        write(1, "Error: this line is out of range\n", 33);
        return (1);
    }
    return (0);
}

int error_matches_suite(int nb, int nb_max, int nb_pipe)
{
    if (nb > nb_max) {
        write(1, "Error: you cannot remove more than ", 35);
        my_put_nbr(nb_max);
        write(1, " matches per turn\n", 18);
        return (1);
    }
    if ((nb > nb_pipe)) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (1);
    }
    if ((nb <= nb_max && nb > nb_pipe)) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (1);
    }
    return (0);
}

int error_matches(char *buffer, int nb_max, int line, char **map)
{
    int i = 0;
    int nb_pipe = 0;

    if (!buffer)
        return (1);
    nb_pipe = det_nb_line(map, line);
    i = my_getnbr(buffer);
    if (my_str_isnum(buffer) == 1 || check_minus(buffer) == 1) {
        write(1, "Error: invalid input (positive number expected)\n", 48);
        return (1);
    }
    if (i <= 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (1);
    }
    if (error_matches_suite(i, nb_max, nb_pipe) == 1)
        return (1);
    return (0);
}
