/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** map_scale
*/

#include "my_rpg.h"

int map_scale_all(isow_t *isow, float scale)
{
    map_scale(&isow->map, scale);
    map_scale(&isow->map_water, scale);
    object_set_size(&isow->player, isow->map.sampling.x, isow->map.sampling.y,
    isow->map.sampling.x * 3);
    object_set_size(&isow->prison, isow->map.sampling.x * 23,
    isow->map.sampling.y * 25, isow->map.sampling.x * 20);
    return EXIT_SUCCESS;
}

int map_scale(map_t *map, float scale)
{
    if ((map->sampling.x != 0) || (map->sampling.x == 0 && scale > 0))
        map->sampling.x += scale;
    if ((map->sampling.y != 0) || (map->sampling.y == 0 && scale > 0))
        map->sampling.y += scale;
    if ((map->sampling.z != 0) || (map->sampling.z == 0 && scale > 0))
        map->sampling.z += scale * 10 / 64;
    map->modified = sfTrue;
    return EXIT_SUCCESS;
}
