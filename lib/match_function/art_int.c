/*
** EPITECH PROJECT, 2020
** IA
** File description:
** IA
*/

#include "../../include/matchstick.h"

void remove_pipe_ia(char **map, int line, int size)
{
    int i = 0;

    for (; map[line][i] != '|'; i += 1);
    for (; map[line][i] == '|'; i += 1);
    i -= 1;
    write (1, "AI removed 1", 12);
    write(1, " match(es) from line ", 21);
    my_put_nbr(line);
    write(1, "\n", 1);
    for (int j = 0; j < 1; j += 1) {
        map[line][i] = ' ';
        i -= 1;
    }
    print_board(map, size);
}

int det_line_to_remove(char **map, int line)
{
    for (int i = 0; i < line; i += 1)
        for (int j = 0; map[i][j]; j += 1)
            if (map[i][j] == '|')
                return (i);
    return (0);
}

void ia_move(char **map, int size, int todo)
{
    int line = det_line_to_remove(map, size);

    if (todo == 1)
        return;
    write(1, "AI's turn...\n", 13);
    remove_pipe_ia(map, line, size);
}