/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function
*/

#include "include/matchstick.h"

int main(int argc, char **argv)
{
    if (argc != 3) {
        return (84);
    }
    if (error_arg(argv) == 84) {
        printf("done\n");
        return (84);
    }
    char **map = print_game_board(my_getnbr(argv[1]));
    moves(map, my_getnbr(argv[2]), my_getnbr(argv[1]));
    return (0);
}