#include "parse.h"

bool validate_map_closed(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->width)
    {
        if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
            return (false);
        i++;
    }

    j = 0;
    while (j < map->height)
    {
        if (map->grid[j][0] != '1' || map->grid[j][map->width - 1] != '1')
            return (false);
        j++;
    }
    return (true);
}

bool validate_map(t_map *map)
{
    if (!validate_required_elements(map))
    {
        printf("Error: Missing required elements\n");
        return (false);
    }
    
    if (!validate_map_characters(map))
    {
        printf("Error: Invalid characters in map\n");
        return (false);
    }
    
    if (!validate_map_closed(map))
    {
        printf("Error: Map is not properly closed\n");
        return (false);
    }
    
    return (true);
}