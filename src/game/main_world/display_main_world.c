/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_main_world
*/

#include "my_rpg.h"

void display_main_world(game_t *game)
{
    sfRenderWindow_drawSprite(game->w.window, game->wmain->sprite, NULL);
}