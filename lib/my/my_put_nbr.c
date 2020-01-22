/*
** EPITECH PROJECT, 2019
** CPool_Day06
** File description:
** my_put_nbr.c
*/
#include "../../include/matchstick.h"

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb *= -1;
    }

    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + 48);
    } else {
        my_putchar((nb % 10) + 48);
    }
    return nb;
}