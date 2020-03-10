/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** main
*/
#include <stdlib.h>
#include "include/my.h"
#include "include/get_next_line.h"

void print(char **map, match_t *(*game))
{
    my_putstr("Player removed ");
    my_put_nbr((*game)->stick);
    my_putstr(" match(es) from line ");
    my_put_nbr((*game)->line);
    my_putchar('\n');
    map = rm_matches(map, (*game)->line, (*game)->stick);
    print_map(map, (*game)->size);
    (*game)->state = lose_game(map, &*game);
}

int game_loop(match_t **game, char **map)
{
    while ((*game)->state != 3) {
        if ((*game)->state == 1) {
            my_putstr("\nYour turn:\n");
            (*game) = my_turn(map, &*game);
        } else if ((*game)->state == 2) {
            (*game) = ai_turn(map, &*game);
        }
    }
    for (int i = 0; i < ((*game)->nb_line + 2); i++) {
        free(map[i]);
    }
    free(map);
    return ((*game)->state);
}

int main(int ac, char **av)
{
    match_t *game = NULL;
    game = malloc(sizeof(match_t));
    char **map = NULL;
    int *tab = 0;
    int end = 0;

    if (error_g(ac, av) == 84)
        return (84);
    check_error(av);
    game->nb_line = my_getnbr(av[1]);
    game->nb_matches = my_getnbr(av[2]);
    game->state = 1;
    game->end = 0;
    game->size = my_getnbr(av[1]);
    tab = create_tab_int(game->size);
    map = create_map(game->nb_line, tab);
    print_map(map, game->size);
    game->state = game_loop(&game, map);
    free(tab);
    end = game->end;
    free(game);
    return (end);
}