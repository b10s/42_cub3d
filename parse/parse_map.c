#include "parse.h"

bool parse_map_grid(t_map *map, t_map_data *data, int start_line)
{
    // マップの行数を計算
    map->height = data->line_count - start_line;
    if (map->height <= 0)
        return (false);
    
    // マップの幅を計算（最大の行の長さ）
    map->width = 0;
    for (int i = start_line; i < data->line_count; i++)
    {
        int len = strlen(data->lines[i]);
        if (len > map->width)
            map->width = len;
    }
    
    // 2次元配列を確保
    map->grid = malloc(sizeof(char *) * map->height);
    if (!map->grid)
        return (false);
    
    // マップデータをコピー
    for (int i = 0; i < map->height; i++)
    {
        map->grid[i] = malloc(sizeof(char) * (map->width + 1));
        if (!map->grid[i])
        {
            // エラー処理: メモリ確保失敗
            for (int j = 0; j < i; j++)
                free(map->grid[j]);
            free(map->grid);
            map->grid = NULL;
            return (false);
        }
        
        // 行をコピーし、足りない部分はスペースで埋める
        int j;
        int line_len = strlen(data->lines[start_line + i]);
        for (j = 0; j < line_len; j++)
            map->grid[i][j] = data->lines[start_line + i][j];
        while (j < map->width)
            map->grid[i][j++] = ' ';
        map->grid[i][j] = '\0';
    }
    
    return (true);
}