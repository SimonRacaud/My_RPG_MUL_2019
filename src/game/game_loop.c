/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Created: 2020-03-28T08:32:14+01:00 | Author: simon
*/

#include "my_rpg.h"
#include "particles.h"

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

static int run(game_t *game, particles_pack_t *pack)
{
    sfRenderWindow_clear(game->w.window, sfBlack);
    /*crossroads(game);
    if (game->state == ERR)
        return EXIT_ERROR;*/
    draw_particles(pack);
    update_particles(pack, game->w);
    sfRenderWindow_display(game->w.window);
    return EXIT_SUCCESS;
}

int game_loop(game_t *game)
{
    sfEvent event;

    particles_pack_t *pack = create_particles(game->w, 1, sfBlue, 20);
    set_particles_pos(pack, (sfVector2f) {700, 500}, 20);
    while (sfRenderWindow_isOpen(game->w.window)) {
        while (sfRenderWindow_pollEvent(game->w.window, &event))
            call_event_manager(game, &event);
        if (run(game, pack) == EXIT_ERROR)
            return EXIT_ERROR;
        if (game->state == QUIT) {
            event_window_close(game);
        }
    }
    destroy_particles(pack);
    return EXIT_SUCCESS;
}
