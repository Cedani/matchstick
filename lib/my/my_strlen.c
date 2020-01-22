/*
** EPITECH PROJECT, 2019
** CPool_Day04
** File description:
** my_strlen.c
*/

#include "../../include/matchstick.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i += 1);
    return (i);
}