#include "parse.h"

bool parse_texture(t_map *map, char *line)
{
    char **split = ft_split(line, ' ');
    if (!split || !split[0] || !split[1] || split[2])
    {
        free_split(split);
        return (false);
    }
    
    // 識別子に応じてパスを保存
    if (strncmp(split[0], "NO", 3) == 0)
        map->no_texture = strdup(split[1]);
    else if (strncmp(split[0], "SO", 3) == 0)
        map->so_texture = strdup(split[1]);
    else if (strncmp(split[0], "WE", 3) == 0)
        map->we_texture = strdup(split[1]);
    else if (strncmp(split[0], "EA", 3) == 0)
        map->ea_texture = strdup(split[1]);
    else
    {
        free_split(split);
        return (false);
    }
    
    free_split(split);
    return (true);
}
