/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** particles header
*/

#ifndef H_PARTICLES
#define H_PARTICLES

#include <SFML/Graphics.h>
#include "window_t.h"
#include "graph.h"

#define EXIT_ERROR 84
#define MAX_ID 1
#define MAX_PARTICLES 100

typedef struct jump_pixels_s
{
    sfVector2f coord;
    float height;
    float start_height;
    float end_height;
    sfColor color;
} jump_pixels_t;

typedef union tpe_part_s
{
    jump_pixels_t *jump_pixels;
} tpe_part_t;

typedef struct particles_pack_s
{
    int id;
    tpe_part_t tpe_part;
    sfTexture *texture;
    sfSprite *sprite;
    framebuffer_t *framebuffer;
} particles_pack_t;

particles_pack_t *create_particles(window_t window, int const id,
                                sfColor color, float size);
int draw_particles(particles_pack_t *pack);
void destroy_particles(particles_pack_t *pack);
void set_particles_pos(particles_pack_t *pack, sfVector2f pos, int radius);
void update_particles(particles_pack_t *pack, window_t win);

//jump pixels
int create_jump_pixels(tpe_part_t *tpe_part, sfColor color, float size);
void destroy_jump_pixels(tpe_part_t tpe_part);
void set_pos_jump_pixels(tpe_part_t *tpe_part, sfVector2f coord, int radius);
int draw_jump_pixels(particles_pack_t *pack);

#endif