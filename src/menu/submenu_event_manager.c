/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-04-23T13:29:58+02:00 | Author: simon
*/

#include "my_rpg.h"

static const sfKeyCode SHORTCUT_SUBMENU[NB_SUB_MENU] =
{
    sfKeyO,
    sfKeyE,
    0,
    sfKeyR
};

static void do_action(game_t *game)
{
    if (game->submenu == MINVSTAT) {
        INVENTORY.pos.x = GET_VAR_DEC(game, "INVENTORY_POSX", NULL);
        INVENTORY.pos.y = GET_VAR_DEC(game, "INVENTORY_POSY", NULL);
    } else if (game->submenu == MINV) {
        INVENTORY.pos.x = 0;
        INVENTORY.pos.y = 0;
    }
}

void submenu_event_manager(game_t *game, sfEvent *event)
{
    if (!game || !event || event->type != sfEvtKeyReleased) {
        return;
    }
    for (size_t i = 0; i < NB_SUB_MENU; i++) {
        if (event->key.code == SHORTCUT_SUBMENU[0]
            && (size_t)game->submenu != i) {
        WMAIN->is_player_move = false;
        }
        if (event->key.code == SHORTCUT_SUBMENU[i]
                && (size_t)game->submenu != i) {
            game->submenu = i;
        } else if (event->key.code == SHORTCUT_SUBMENU[i]) {
            game->submenu = NO_MENU;
        }
    }
    do_action(game);
}
