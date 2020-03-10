/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** end_game
*/

#include "include/my.h"

char **create_map(int size, int *tab)
{
    int lenght = (size * 2) + 1;
    int size_map = size + 2;
    char **map = malloc(sizeof(char *) * size_map);

    for (int i = 0; i < size_map; i++) {
        map[i] = malloc(sizeof(char) * (lenght + 1));
    }
    set_map(map, size_map, lenght);
    map = set_matches(map, tab, size);
    return (map);
}

int end_game(char **map, match_t *game)
{
    int k = 0;

    for (int i = 0; i <= (game->nb_line); i++) {
        for (k = 0; map[i][k] != '\0'; k++) {
            if (map[i][k] == '|') {
                return (0);
            }
        }
    }
    return (1);
}

int lose_game(char **map, match_t *(*game))
{
    if (end_game(map, *game) == 1) {
        my_putstr("You lost, too bad...\n");
        (*game)->end = 2;
        return (3);
    }
    return (2);
}

int win_game(char **map, match_t *(*game))
{
    if (end_game(map, *game) == 1) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        (*game)->end = 1;
        return (3);
    }
    return (1);
}