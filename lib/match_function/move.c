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

int check_win(char **tab, int size)
{
    for (int i = 0; i < size; i += 1)
        for (int j = 0; tab[i][j]; j += 1)
            if (tab[i][j] == '|')
                return (1);
    return (0);
}

void moves(char **map, int nb_max, int line)
{
    char *buffer = NULL;
    size_t usl = 0;
    int ok = 0;
    int check = 1;
    int given_line = 0;

    while (usl != -1 && check_win(map, line) != 0) {
        write(1, "Line: ", 6);
        usl = getline(&buffer, &usl, stdin);
        if (usl != -1)
            check = error_line(buffer, line);
        if (check != 1) {
            ok = my_getnbr(buffer);
            write(1, "Matches: ", 9);
            getline(&buffer, &usl, stdin);
            check = error_matches(buffer, nb_max, ok, map);
        }
        if (check != 1)
            print_updated_board_game(map, ok, my_getnbr(buffer), line);
        ia_move(map, line + 2, check);
    }
}