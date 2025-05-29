#include "parse.h"

void print_map(t_map *map)
{
    int i;

    printf("Map Dimensions: %d x %d\n", map->width, map->height);
    printf("Textures:\n");
    printf("  NO: %s\n", map->no_texture);
    printf("  SO: %s\n", map->so_texture);
    printf("  WE: %s\n", map->we_texture);
    printf("  EA: %s\n", map->ea_texture);

    printf("Colors:\n");
    printf("  Floor:   #%02X%02X%02X\n",
           (map->floor_color >> 16) & 0xFF,
           (map->floor_color >> 8) & 0xFF,
           map->floor_color & 0xFF);
    printf("  Ceiling: #%02X%02X%02X\n",
           (map->ceiling_color >> 16) & 0xFF,
           (map->ceiling_color >> 8) & 0xFF,
           map->ceiling_color & 0xFF);

    printf("Grid:\n");
    for (i = 0; i < map->height; i++)
    {
        printf("  %s\n", map->grid[i]);
    }
}
