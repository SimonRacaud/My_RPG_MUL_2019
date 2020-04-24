/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T10:16:31+01:00 | Author: simon
*/

#include "my_rpg.h"

extern FUNC_EVENT fct_event[NB_GAME_STATE];
extern FUNC_EVENT fct_event_sub_menu[NB_SUB_MENU];

static const sfKeyCode FORCE_QUIT_KEY = sfKeyW;
static const sfKeyCode PAUSE_MENU_KEY = sfKeySpace;

void event_window_close(game_t *game)
{
    sfRenderWindow_close(game->w.window);
}

static bool check_quit_event(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtClosed || game->state == QUIT) {
        event_window_close(game);
        return true;
    }
    if (sfKeyboard_isKeyPressed(FORCE_QUIT_KEY)) {
        event_window_close(game);
        return true;
    }
    return false;
}

static void event_crossroads(game_t *game, sfEvent *event)
{
    if (game->state == QUIT || game->state == ERR) {
        return;
    }
    if (game->submenu != NO_MENU && fct_event_sub_menu[game->submenu]
            && (game->state == MAIN_WORLD || game->state == ISO_WORLD)) {
        fct_event_sub_menu[game->submenu](game, event);
        return;
    }
    if (game->state == MAIN_WORLD || game->state == ISO_WORLD) {
        submenu_event_manager(game, event);
    }
    if (game->sysquest.play_dialogue == true && (game->state == MAIN_WORLD
            || game->state == ISO_WORLD || game->state == FIGHT_MODE)) {
        if (dialogue_event_manager(game, event) == true) {
            return;
        }
    }
    if (fct_event[game->state] != NULL) {
        fct_event[game->state](game, event);
    }
}

void call_event_manager(game_t *game, sfEvent *event)
{
    if (check_quit_event(game, event)) {
        return;
    } else if (is_key_pressed(event, PAUSE_MENU_KEY)
        && (game->state != MAIN_MENU && game->state != OPTION_MENU)) {
        set_game_state(game, PAUSE_MENU);
        return;
    }
    input_manage(game, event);
    event_crossroads(game, event);
}
