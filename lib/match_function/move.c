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

int moves(char **map, int nb_max, int line)
{
    char *buffer = NULL;
    size_t usl = 0;
    int ok = 0;
    int check = 2;
    int given_line = 0;
    int ret;

    while (usl != -1 && check_win(map, line + 2) != 0) {
        if (check == 2)
            write(1, "Your Turn: \n", 13);
        write(1, "Line: ", 6);
        usl = getline(&buffer, &usl, stdin);
        if (usl != -1)
            check = error_line(buffer, line);
        else
            check = 1;
        if (check != 1) {
            ok = my_getnbr(buffer);
            write(1, "Matches: ", 9);
            getline(&buffer, &usl, stdin);
            check = error_matches(buffer, nb_max, ok, map);
        }
        if (check != 1) {
            print_updated_board_game(map, ok, my_getnbr(buffer), line);
            check = 2;
            if (check_win(map, line + 2) == 0) {
                write(1, "You lost, too bad...\n", 21);
                return (2);
            }
        }
        ia_move(map, line + 2, check);
        if (check_win(map, line + 2) == 0) {
            write(1, "I lost... snif... but I'll get you next time!!\n", 47);
            return (1);
        }
    }
    return (0);
}