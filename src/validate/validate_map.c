#include "../../includes/cub3d.h"

bool validate_map_closed(t_map *map)
{
    // 各「0」と「N,S,E,W」の周囲が壁または有効なマップ領域であることを確認
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            char c = map->grid[i][j];
            
            if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                // 境界チェック
                if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
                    return (false);
                
                // 周囲のセルをチェック
                if (map->grid[i-1][j] == ' ' || map->grid[i+1][j] == ' ' || 
                    map->grid[i][j-1] == ' ' || map->grid[i][j+1] == ' ')
                    return (false);
            }
        }
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