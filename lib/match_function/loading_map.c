/*
** EPITECH PROJECT, 2020
** loading_map.c
** File description:
** generating map
*/

#include "../../include/matchstick.h"

void fill_middle(char *line, int index, int middle, int line_el)
{
    int i = 0;

    for (; i < line_el; i += 1) {
        if (i > middle - index - 1 && i < middle + index - 1)
            line[i] = '|';
        else if (i == 0 || i == line_el - 1)
            line[i] = '*';
        else
            line[i] = ' ';
    }
    line[i] = '\0';
}

void fill_extremities(char *line, int nb_el)
{
    int i = 0;
    for (; i < nb_el; i += 1)
        line[i] = '*';
    line[i] = '\0';
}

char **print_game_board(int nb_line)
{
    int line = nb_line + 2;
    int nb_el = 1;
    int j = 0;
    char **tab = malloc(sizeof(*tab) * line);

    for (int i = 0; i < line - 2; i += 1)
        nb_el += 2;
    for (; j < line; j += 1) {
        tab[j] = malloc(sizeof(*tab[j]) * nb_el + 1);
        if (j == 0 || j == line - 1)
            fill_extremities(tab[j], nb_el);
        else
            fill_middle(tab[j], j, nb_el / 2 + 1, nb_el);
    }
    print_board(tab, line);
    return (tab);
}

void print_board(char **map, int size)
{
    for (int i = 0; i < size; i += 1) {
        write(1, map[i], my_strlen(map[i]));
        write(1, "\n", 1);
    }
}