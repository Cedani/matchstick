/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main function
*/

#include "include/matchstick.h"

int main(int argc, char **argv)
{
    char **map = print_game_board(my_getnbr(argv[1]));
    moves(map, my_getnbr(argv[2]), my_getnbr(argv[1]));
    return (0);
}