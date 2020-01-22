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

int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int attrib_sign(char const *str, int i);
int attrib_num(char const *str, int i);
void my_putchar(char c);
char **print_game_board(int nb_line);
#endif /* !MATCHSTICK */
