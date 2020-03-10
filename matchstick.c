/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** matchstick
*/

#include "include/my.h"
#include "include/get_next_line.h"

int *create_tab_int(int size)
{
    int i = 1;
    int nbr_matches = 1;
    int *map = malloc(sizeof(int *) * (size + 4));
    map[0] = 0;

    for (; i <= size; i++) {
        map[i] = nbr_matches;
        nbr_matches += 2;
    }
    return (map);
}

char **rm_matches(char **map, int line, int stick)
{
    for (int i = my_strlen(map[line]); stick > 0; i--) {
        if (map[line][i] == '|') {
            map[line][i] = ' ';
            stick--;
        }
    }
    return (map);
}

void print_map(char **map, int size)
{
    int i = 0;

    for (i = 0; i <= size + 1; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

char **set_matches(char **map, int *tab, int size)
{
    int x = 0;
    int y = 0;
    int i = size + 1;
    int k = size + 1;

    for (; x <= size; i--, k--) {
        if (k <= size) {
            for (y = 0; y < tab[k] && tab[k] != 0; y++) {
                map[i][x + y] = '|';
            }
        }
        x++;
    }
    return (map);
}

void set_map(char **map, int size, int lenght)
{
    int i;
    int x;

    for (i = 0; i != size; i++) {
        for (x = 0; x != lenght; x++) {
            if (i == 0 || i == size - 1)
                map[i][x] = '*';
            else if (x == 0 || x == lenght - 1)
                map[i][x] = '*';
            else
                map[i][x] = ' ';
        }
        map[i][x] = 0;
    }
}