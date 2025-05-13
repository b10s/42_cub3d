
#include "../includes/cub3d.h"

/**
 * キー押下イベントのハンドラー
 * ESCキーが押されたらウィンドウを閉じる
 */
int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

/**
 * ウィンドウを閉じて、プログラムを終了する
 */
int	close_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

/**
 * MLXのイベントフックを設定
 */
static void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, EVENT_KEY_PRESS, 0, key_press, game);
	mlx_hook(game->win, EVENT_CLOSE, 0, close_window, game);
}

/**
 * エラーメッセージを表示して終了
 */
static void	error_exit(char *message)
{
	printf("Error\n%s\n", message);
	exit(1);
}

/**
 * ゲーム関連のデータを初期化
 */
static void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	
	// マップ構造体の初期化はparse_map内で行う
}

/**
 * MiniLibXを初期化してウィンドウを作成
 */
static void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Failed to initialize MLX");
	
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (!game->win)
		error_exit("Failed to create window");
}

/**
 * メイン関数 - プログラムのエントリーポイント
 */
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Usage: %s <map.cub>\n", argv[0]);
		return (1);
	}
	
	init_game(&game);
	
	// マップのパース
	if (parse_map(&game, argv[1]) != 0)
		return (1);
	
	init_mlx(&game);
	setup_hooks(&game);
	
	printf("Window initialized successfully.\n");
	printf("Press ESC or click the close button to exit.\n");
	
	mlx_loop(game.mlx);
	return (0);
}