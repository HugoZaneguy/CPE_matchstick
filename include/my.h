/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** my
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef MY_H_
#define MY_H_

typedef struct match_s {
    int line;
    int stick;
    int state;
    int size;
    int nb_matches;
    int nb_line;
    int end;
    int back;
    int pos;
} match_t;

int error_g(int ac, char **av);
int check_error(char **av);
int main(int ac, char **av);
int *create_tab_int(int size);
void print_map(char **map, int size);
char **set_matches(char **map, int *tab, int size);
char **rm_matches(char **map, int line, int stick);
int my_strlen(char const *str);
void set_map(char **map, int size, int lenght);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_getnbr(char const *str);
char **create_map(int size, int *tab);
match_t *my_turn(char **map, match_t *(*game));
match_t *ai_turn(char **map, match_t *(*game));
int randome(int s);
void check_line(char **map, int line, match_t *game);
int check_empty_line(char **map, int line);
int end_game(char **map, match_t *game);
int lose_game(char **map, match_t **game);
int win_game(char **map, match_t **game);
int match_error(match_t *game, char **map, int type, int status);
int line_turn(char **map, match_t *(*game));
int stick_turn(char **map, match_t *(*game));
int only_figures(char *str);
void print(char **map, match_t *(*game));

#endif /* !MY_H_ */