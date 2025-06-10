#include "parse.h"

int calculate_map_width(t_map_data *data, int start_line)
{
    int max_width;
    int i;

    max_width = 0;
    i = start_line;
    while(i < data->line_count)
    {
        int len = ft_strlen(data->lines[i]);
        if(len > max_width)
            max_width = len;
        i++;
    }
    return (max_width);
}

void cleanup_grid(char **grid, int allocated_rows)
{
    int i;
    
    i = 0;
    while (i < allocated_rows)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}


void copy_and_pad_line(char *dest, const char *src, int target_width)
{
    int j;
    int src_len;

    j = 0;
    src_len = ft_strlen(src);

    while (j < src_len)
    {
        dest[j] = src[j];
        j++;
    }
    while (j < target_width)
    {
        dest[j] = ' ';
        j++;
    }
    dest[j] = '\0';
}

bool parse_map_grid(t_map *map, t_map_data *data, int start_line)
{
    map->height = data->line_count - start_line;
    if(map->height <= 0)
        return (false);

    map->width = calculate_map_width(data, start_line);
    map->grid = malloc(sizeof(char *) * map->height);
    if(!map->grid)
        return (false);

    int i;
    i = 0;
    while (i < map->height)
    {
        map->grid[i] = malloc(sizeof(char) * (map->width + 1));
        if(!map->grid[i])
        {
            cleanup_grid(map->grid, i);
            map->grid = NULL;
            return (false);
        }
        copy_and_pad_line(map->grid[i], data->lines[start_line + i], map->width);
        i++;
    }
    return (true);
}