/*
** EPITECH PROJECT, 2020
** move.c
** File description:
** defining ai move and player move
*/

#include "../../include/matchstick.h"

void print_updated_board_game(char **tab, int line, int nb_matches, int size)
{
    int i = 0;
    for (; tab[line][i] != '|'; i += 1);
    for (; tab[line][i] == '|'; i += 1);
    i -= 1;

    write (1, "Player removed ", 15);
    my_put_nbr(nb_matches);
    write(1, " match(es) from line ", 21);
    my_put_nbr(line);
    write(1, "\n", 1);
    for (int j = i; nb_matches > 0; j -= 1) {
        tab[line][j] = ' ';
        nb_matches -= 1;
    }
    print_board(tab, size + 2);
}

void pl_ia_move(move_t *pl, char **map)
{
    if (pl->ret != 2) {
        ia_move(map, pl->line_max + 2, pl->check);
        if (check_win(map, pl->line_max + 2) == 0) {
            write(1, "I lost... snif... but I'll get you next time!\n", 47);
            pl->ret = 1;
        }
    }
}

int match_input(char **map, move_t *pl)
{
    pl->line = my_getnbr(pl->buffer);
    pl->check = 1;

    write(1, "Matches: ", 9);
    pl->usl = getline(&pl->buffer, &pl->usl, stdin);
    if (pl->usl != -1) {
        pl->check = error_matches(pl->buffer, pl->nb_max, pl->line, map);
        pl->ok = my_getnbr(pl->buffer);
    }
    if (pl->check != 1) {
        print_updated_board_game(map, pl->line, pl->ok, pl->line_max);
        pl->check = 2;
        if (check_win(map, pl->line_max + 2) == 0) {
            write(1, "You lost, too bad...\n", 21);
            pl->ret = 2;
        }
    }
    pl_ia_move(pl, map);
}

int check_win(char **tab, int size)
{
    for (int i = 0; i < size; i += 1)
        for (int j = 0; tab[i][j]; j += 1)
            if (tab[i][j] == '|')
                return (1);
    return (0);
}

int moves(char **map, int nb_max, int line)
{
    move_t *pl = malloc(sizeof(*pl));
    pl->check = 2;
    pl->ret = 0;
    pl->line_max = line;
    pl->nb_max = nb_max;

    while (check_win(map, line + 2) != 0 && pl->usl != -1) {
        if (pl->check == 2)
            write(1, "Your Turn:\n", 11);
        write(1, "Line: ", 6);
        pl->check = 1;
        pl->usl = getline(&pl->buffer, &pl->usl, stdin);
        if (pl->usl != -1)
            pl->check = error_line(pl->buffer, line);
        if (pl->check != 1)
            match_input(map, pl);
        if (pl->ret != 0)
            return (pl->ret);
    }
    return (pl->ret);
}