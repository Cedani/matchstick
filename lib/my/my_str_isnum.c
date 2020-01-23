/*
** EPITECH PROJECT, 2020
** str_isnum
** File description:
** str_isnum
*/

int jump_nonnum(char const str);

int my_str_isnum(char const *str)
{
    for (int j = 0; str[j] != '\0' && str[j] != '\n'; j += 1) {
        if (str[j] == '-' && j != 0)
            return (1);
        if (jump_nonnum(str[j]) == 1) {
            return (1);
        }
    }
    return (0);
}

int jump_nonnum(char const str)
{
    if (str >= '0' && str <= '9' || str == '-')
        return (0);
    else
        return (1);
}
