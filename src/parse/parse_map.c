#include "../../includes/cub3d.h"

/**
 * マップ構造体を初期化する
 */
static void	init_map(t_map *map)
{
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->we_texture = NULL;
	map->ea_texture = NULL;
	map->floor_color = 0;
	map->ceiling_color = 0;
}

/**
 * マップ解析のエントリーポイント
 * ファイルの存在確認と拡張子チェックを行う
 * 
 * @param game ゲーム構造体ポインタ
 * @param map_path マップファイルのパス
 * @return 成功時は0、失敗時は1
 */
int	parse_map(t_game *game, char *map_path)
{
	int	fd;
	
	// 拡張子チェック (.cub)
	if (map_path == NULL || 
		(map_path[0] == '\0') || 
		(ft_strncmp(map_path + ft_strlen(map_path) - 4, ".cub", 4) != 0))
	{
		printf("Error\nInvalid map file extension. Must be .cub\n");
		return (1);
	}
	
	// ファイルの存在確認
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open map file: %s\n", map_path);
		return (1);
	}
	
	// マップ構造体の初期化
	init_map(&game->map);
	
	// ファイルを閉じる
	close(fd);
	
	// ここから本格的なパース処理を実装予定
	printf("Map file found and valid: %s\n", map_path);
	
	return (0);
}