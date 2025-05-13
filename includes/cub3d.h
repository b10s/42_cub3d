#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Libft/include/libft.h"
# include "../minilibx-linux/mlx.h"

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 600
# define WINDOW_TITLE "cub3D"

/* キーコード定義 (MacOSとLinuxで異なる場合があります) */
# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

/* イベントコード定義 */
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_CLOSE 17

/* マップ情報構造体 */
typedef struct s_map
{
	char	**grid;         /* 2次元マップ配列 */
	int		width;          /* マップの幅 */
	int		height;         /* マップの高さ */
	char	*no_texture;    /* 北向きテクスチャパス */
	char	*so_texture;    /* 南向きテクスチャパス */
	char	*we_texture;    /* 西向きテクスチャパス */
	char	*ea_texture;    /* 東向きテクスチャパス */
	int		floor_color;    /* 床の色 (RGB) */
	int		ceiling_color;  /* 天井の色 (RGB) */
}	t_map;

/* ゲームの基本構造体 */
typedef struct s_game
{
	void	*mlx;           /* MLXポインタ */
	void	*win;           /* ウィンドウポインタ */
	t_map	map;            /* マップ情報 */
}	t_game;

/* 関数プロトタイプ */
/* マップパース関連 */
int		parse_map(t_game *game, char *map_path);

/* キーボード操作 */
int		key_press(int keycode, t_game *game);
/* ウィンドウ関連 */
int		close_window(t_game *game);

#endif