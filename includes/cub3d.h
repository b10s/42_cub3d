#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../Libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"


# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 600
# define WINDOW_TITLE "cub3D"

# define SUCCESS 0
# define FAILURE 1
# define INITIAL_CAPACITY 16

#define KEY_ESC        53
#define EVENT_KEY_PRESS 2
#define EVENT_CLOSE     17

// 構造体定義
typedef struct s_map_data
{
    char **lines;
    int line_count;
    int capacity;
} t_map_data;

typedef struct s_map
{
    char **grid;
    int width;
    int height;
    char *no_texture;
    char *so_texture;
    char *we_texture;
    char *ea_texture;
    int floor_color;
    int ceiling_color;
} t_map;

typedef struct s_player
{
    double x;
    double y;
    char direction;
} t_player;

typedef struct s_game
{
	void	*mlx;           /* MLXポインタ */
	void	*win;           /* ウィンドウポインタ */
	t_map	map;            /* マップ情報 */
    t_player player;      /* プレイヤー情報 */
}	t_game;

// 関数プロトタイプ
// ファイル操作
char *get_next_line(int fd);
int check_map_file(char *arg, bool cub);

// マップ解析
int parse_map(t_game *game, char *map_path);
int parse_map_format(char *map_path);
bool parse_map_grid(t_map *map, t_map_data *data, int start_line);
bool parse_texture(t_map *map, char *line);
bool parse_color(t_map *map, char *line);

// マップデータ操作
void init_map_data(t_map_data *data);
void add_line(t_map_data *data, char *line);
void free_map_data(t_map_data *data);

// バリデーション
bool validate_required_elements(t_map *map);
bool validate_map_characters(t_map *map);
bool validate_map_closed(t_map *map);
bool validate_map(t_map *map);
bool find_player_position(char **grid, t_player *player);

// ユーティリティ
bool is_empty_line(char *line);
char *trim_whitespace(char *str);
void free_map(t_map *map);
void free_split(char **split);

// キーボード操作
int key_press(int keycode, t_game *game);
// ウィンドウ関連
int close_window(t_game *game);


#endif
