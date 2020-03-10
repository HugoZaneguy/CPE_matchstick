/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** map
*/

#include "include/my.h"
#include "include/get_next_line.h"
#include <time.h>

match_t *my_turn(char **map, match_t *(*game))
{
    (*game)->back = line_turn(map, &*game);
    if ((*game)->back ==  1)
        return (*game);
    (*game)->back = stick_turn(map, &*game);
    if ((*game)->back ==  1) {
        return (*game);
    } else if ((*game)->back == 2) {
        *game = my_turn (map, &*game);
        return (*game);
    }
    print(map, &*game);
    return (*game);
}

match_t *ai_turn(char **map, match_t *(*game))
{
    int stick = 0;

    check_line(map, (*game)->line, *game);
    (*game)->stick = randome(stick);
    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr((*game)->stick);
    my_putstr(" match(es) from line ");
    my_put_nbr((*game)->line);
    my_putchar('\n');
    map = rm_matches(map, (*game)->line, (*game)->stick);
    print_map(map, (*game)->size);
    (*game)->state = win_game(map, &*game);
    return (*game);
}

int line_turn(char **map, match_t *(*game))
{
    char *check = NULL;
    int back = 0;

    my_putstr("Line: ");
    check = get_next_line(0);
    if (check == 0) {
        (*game)->state = 3;
        (*game)->end = 0;
        return (1);
    }
    (*game)->line = my_getnbr(check);
    if ((*game)->line < 0 || only_figures(check) == 1) {
        my_putstr("Error: input (positive number expected)\n");
        back = line_turn(map, &*game);
    }
    if ((*game)->nb_line < (*game)->line || (*game)->line == 0) {
        my_putstr("Error: this line is out of range\n");
        back = line_turn(map, &*game);
    }
    return (back);
}

int stick_turn_bis(char **map, match_t *(*game))
{
    if (check_empty_line(map, (*game)->line) < (*game)->stick) {
        my_putstr("Error: not enough matches on this line\n");
        return (2);
    }
    if ((*game)->stick == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (2);
    }
    if ((*game)->nb_matches < (*game)->stick) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr((*game)->nb_matches);
        my_putstr(" matches per turn\n");
        return (2);
    }
    return (0);
}

int stick_turn(char **map, match_t *(*game))
{
    char *check = NULL;
    int back = 0;

    my_putstr("Matches: ");
    check = get_next_line(0);
    if (check == 0) {
        (*game)->state = 3;
        (*game)->end = 0;
        return (1);
    }
    (*game)->stick = my_getnbr(check);
    if ((*game)->stick < 0 || only_figures(check) == 1) {
        my_putstr("Error: input (positive number expected)\n");
        return (2);
    }
    back = stick_turn_bis(map, &*game);
    return (back);
}
