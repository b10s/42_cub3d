#include "../../includes/cub3d.h"

void init_map_data(t_map_data *data)
{
    data->lines = malloc(sizeof(char *) * INITIAL_CAPACITY);
    data->line_count = 0;
    data->capacity = INITIAL_CAPACITY;
}

void add_line(t_map_data *data, char *line)
{
    // 容量が足りない場合は拡張
    if (data->line_count >= data->capacity)
    {
        data->capacity *= 2;
        char **new_lines = malloc(sizeof(char *) * data->capacity);
        
        // 既存のデータをコピー
        for (int i = 0; i < data->line_count; i++)
            new_lines[i] = data->lines[i];
            
        free(data->lines);
        data->lines = new_lines;
    }
    
    // 行を追加
    data->lines[data->line_count++] = line;
}

void free_map_data(t_map_data *data)
{
    for (int i = 0; i < data->line_count; i++)
        free(data->lines[i]);
    free(data->lines);
    data->lines = NULL;
    data->line_count = 0;
    data->capacity = 0;
}