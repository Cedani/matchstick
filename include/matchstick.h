/*
** EPITECH PROJECT, 2020
** matchstick.h
** File description:
** useful functions
*/

#ifndef MATCHSTICK
#define MATCHSTICK
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int attrib_sign(char const *str, int i);
int attrib_num(char const *str, int i);
void my_putchar(char c);
char **print_game_board(int nb_line);
void print_board(char **map, int size);
int my_str_isnum(char const *str);
int error_line(char *buffer, int line);
int error_matches(char *buffer, int nb_max, int line, char **map);
int check_win(char **tab, int size);
void moves(char **map, int nb_max, int line);
#endif /* !MATCHSTICK */
