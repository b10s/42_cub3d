#include "parse.h"
static void init_map(t_map *map)
{
    map->grid = NULL;
    map->width = 0;
    map->height = 0;
    map->no_texture = NULL;
    map->so_texture = NULL;
    map->we_texture = NULL;
    map->ea_texture = NULL;
    map->floor_color = -1;
    map->ceiling_color = -1;
}

static bool parse_file_content(t_map *map, t_map_data *data)
{
    int map_start = 0;
    
    // 設定情報を先に解析
    for (int i = 0; i < data->line_count; i++)
    {
        char *line = data->lines[i];
        
        // 空行をスキップ
        if (is_empty_line(line))
            continue;
            
        // テクスチャ解析
        if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
        {
            if (!parse_texture(map, line))
                return (false);
        }
        // 色情報解析
        else if (line[0] == 'F' || line[0] == 'C')
        {
            if (!parse_color(map, line))
                return (false);
        }
        // マップ開始行を記録
        else if (line[0] == '1' || line[0] == '0' || line[0] == ' ')
        {
            map_start = i;
            break;
        }
    }
    
    // マップグリッドを解析
    if (!parse_map_grid(map, data, map_start))
        return (false);
    
    return (true);
}


t_map *parse_map(char *map_path)
{
    int fd;
    char *line;
    t_map_data data;
    t_map *map;

    // ファイルの存在確認と拡張子チェック
    if (check_map_file(map_path, true) != SUCCESS)
        return NULL;

    // マップ構造体のメモリ確保と初期化
    map = malloc(sizeof(t_map));
    if (!map)
        return NULL;
    init_map(map);

    // マップデータ用動的配列の初期化
    init_map_data(&data);

    // ファイルを開く
    fd = open(map_path, O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n%s: No such file or directory\n", map_path);
        free(map);
        return NULL;
    }

    // ファイル内容を1行ずつ読み取り、保存
    while ((line = get_next_line(fd)) != NULL)
    {
        // 改行文字を削除
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        add_line(&data, line);  // 内部で strdup() などしている想定
        free(line);             // get_next_line が malloc を使用している場合
    }
    close(fd);

    // 読み取った内容を解析
    if (!parse_file_content(map, &data))
    {
        free_map_data(&data);
        free_map(map);
        return NULL;
    }

    // マップの妥当性チェック
    if (!validate_map(map))
    {
        free_map_data(&data);
        free_map(map);
        return NULL;
    }

    free_map_data(&data);
    printf("Map file parsed successfully: %s\n", map_path);
    return map;
}