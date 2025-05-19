#include "../../includes/cub3d.h"
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
	int is_mapfile;
	
	// ファイルの存在確認
	is_mapfile =check_map_file(map_path, true);
	if (is_mapfile != SUCCESS)
	return (FAILURE);

	// TODO: ファイル内容を1行ずつ読み取り、保存する処理を実装する
	parse_map_format(map_path);

	// TODO: 読み取った内容を構造体に分類・保存する処理を実装する
	// TODO: マップ構造の正しさチェック
	// TODO: テクスチャの設定チェック
	// TODO: プレイヤーの位置と向きの初期化


	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n%s: No such file or directory\n", map_path);
		return (FAILURE);
	}	
	// マップ構造体の初期化
	init_map(&game->map);
	
	// ファイルを閉じる
	close(fd);
	printf("Map file found and valid: %s\n", map_path);
	
	return (0);
}