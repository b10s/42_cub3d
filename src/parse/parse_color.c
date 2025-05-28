#include "../../includes/cub3d.h"

bool parse_color(t_map *map, char *line)
{
    char **split = ft_split(line, ' ');
    if (!split || !split[0] || !split[1] || split[2])
    {
        free_split(split);
        return (false);
    }
    
    // RGB値を取得
    char **rgb = ft_split(split[1], ',');
    if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
    {
        free_split(split);
        free_split(rgb);
        return (false);
    }
    
    // 数値に変換
    int r = ft_atoi(rgb[0]);
    int g = ft_atoi(rgb[1]);
    int b = ft_atoi(rgb[2]);
    
    // 値の範囲チェック (0-255)
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    {
        free_split(split);
        free_split(rgb);
        return (false);
    }
    
    // 色を保存 (RGB値を1つの整数にエンコード)
    int color = (r << 16) | (g << 8) | b;
    
    if (strncmp(split[0], "F", 2) == 0)
        map->floor_color = color;
    else if (strncmp(split[0], "C", 2) == 0)
        map->ceiling_color = color;
    else
    {
        free_split(split);
        free_split(rgb);
        return (false);
    }
    
    free_split(split);
    free_split(rgb);
    return (true);
}