#include "parse.h"

void free_map(t_map *map)
{
    if (map->grid)
    {
        for (int i = 0; i < map->height; i++)
            free(map->grid[i]);
        free(map->grid);
    }
    
    free(map->no_texture);
    free(map->so_texture);
    free(map->we_texture);
    free(map->ea_texture);
    
    // 構造体をクリア
    memset(map, 0, sizeof(t_map));
}