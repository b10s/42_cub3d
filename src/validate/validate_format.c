#include "../../includes/cub3d.h"

bool validate_required_elements(t_map *map)
{
    // テクスチャパスの確認
    if (!map->no_texture || !map->so_texture || !map->we_texture || !map->ea_texture)
        return (false);
    
    // 色情報の確認
    if (map->floor_color == -1 || map->ceiling_color == -1)
        return (false);
    
    // マップデータの確認
    if (!map->grid || map->width <= 0 || map->height <= 0)
        return (false);
    
    return (true);
}

bool validate_map_characters(t_map *map)
{
    int player_count = 0;
    
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
        {
            char c = map->grid[i][j];
            
            // 許可された文字かチェック
            if (c != '0' && c != '1' && c != ' ' && 
                c != 'N' && c != 'S' && c != 'E' && c != 'W')
                return (false);
            
            // プレイヤーの数をカウント
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
                player_count++;
        }
    }
    
    // プレイヤーは1人だけ
    if (player_count != 1)
        return (false);
    
    return (true);
}