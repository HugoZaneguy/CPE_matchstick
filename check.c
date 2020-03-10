/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** matchstick
*/

#include "include/my.h"
#include "include/get_next_line.h"

int check_error(char **av)
{
    int i = 1;
    int x = 0;

    for (; i <= 2; i++) {
        for (x = 0; av[i][x] != '\0'; x++) {
            if (!(av[i][x] >= '0' && (av[i][x]) <= '9'))
            return (84);
        }
    }
    return (0);
}

int randome(int s)
{
    int n = 0;
    n = rand();

    if (n <= 0) {
        return (1);
    }
    n = n % (s + 1);
    if (n <= 0) {
        return (1);
    }
    return (n);
}

int check_empty_line(char **map, int line)
{
    int i = 0;
    int k = 0;

    for (i = 0; map[line][i] != '\0'; i++) {
        if (map[line][i] == '|')
            k++;
    }
    return (k);

}

void check_line(char **map, int line, match_t *game)
{
    int k = 0;
    int i = 0;

    game->line = randome(game->nb_line);
    for (i = my_strlen(map[game->line]); i > 0; i--) {
        if (map[game->line][i] == '|')
            k++;
    }
    if (k == 0)
        check_line(map, line, game);
}

int only_figures(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}