/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:32:14+01:00 | Author: simon
*/

#include "my_rpg.h"

extern FUNC_EXEC fct_exec[NB_GAME_STATE];
extern FUNC_EXEC fct_exec_sub_menu[NB_SUB_MENU];

static void crossroads(game_t *game)
{
    if (game->state == QUIT || game->state == ERR) {
        return;
    }
    if (fct_exec[game->state] != NULL)
        fct_exec[game->state](game);
    if (game->sysquest.play_dialogue == true && (game->state == MAIN_WORLD
            || game->state == ISO_WORLD)) {
        dialogue_display(game);
    }
    if (game->submenu != NO_MENU && fct_exec_sub_menu[game->submenu]
            && (game->state == MAIN_WORLD || game->state == ISO_WORLD)) {
        fct_exec_sub_menu[game->submenu](game);
    }
}

static int run(game_t *game)
{
    sfRenderWindow_clear(game->w.window, sfBlack);
    crossroads(game);
    if (game->state == ERR)
        return EXIT_ERROR;
    sfRenderWindow_display(game->w.window);
    if (game->help_popup.is_enable) {
        image_viewer_display(&game->help_popup);
    }
    return EXIT_SUCCESS;
}

int game_loop(game_t *game)
{
    sfEvent event;

    image_viewer_status(&game->help_popup);
    while (sfRenderWindow_isOpen(game->w.window)) {
        while (sfRenderWindow_pollEvent(game->w.window, &event))
            call_event_manager(game, &event);
        if (run(game) == EXIT_ERROR)
            return EXIT_ERROR;
        if (game->state == QUIT) {
            event_window_close(game);
        }
    }
    return EXIT_SUCCESS;
}
