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

typedef struct move_s {
    int check;
    size_t usl;
    char *buffer;
    int line;
    int ok;
    int ret;
    int nb_max;
    int line_max;
} move_t;

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
int moves(char **map, int nb_max, int line);
void ia_move(char **map, int size, int todo);
int error_arg(char **argv);
#endif /* !MATCHSTICK */
