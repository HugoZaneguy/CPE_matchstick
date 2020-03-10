/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** error_g
*/

#include "include/my.h"

int my_isnum(char *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] < 48 || str[i] > 57)
            return (false);
    }
    return (true);
}

int match_error_2(match_t *game, char **map, int status)
{
    for (int j = 0; map[j] != NULL ; j++) {
        if (map[game->line-1][j] == '|')
            status++;
    }
    if (status < game->stick) {
        my_putstr("Error: not enough matches on this line\nLine: ");
        return (1);
    }
    return (0);
}

int error_g_2(char **av)
{
    if (my_getnbr(av[1]) < 2 || my_getnbr(av[1]) > 99)
        return (84);
    if (my_getnbr(av[2]) < 1)
        return (84);
    return (0);
}

int error_g(int ac, char **av)
{
    bool error = false;

    if (ac != 3) {
        my_putstr("to many or to few arguments!\n");
        return (84);
    }
    if ((error = my_isnum(av[1])) == false) {
        my_putstr("Correct usage: ./matchstick <lines> <matches>\n");
        return (84);
    }
    if ((error = my_isnum(av[2])) == false) {
        my_putstr("Correct usage: ./matchstick <lines> <matches>\n");
        return (84);
    }
    if (error_g_2(av) == 84)
        return (84);
    return (0);
}