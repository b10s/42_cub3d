#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../lib/Libft/include/libft.h"
#include "./get_next_line/get_next_line.h"


# define SUCCESS 0
# define FAILURE 1
# define INITIAL_CAPACITY 16

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

typedef struct s_color {
    int red;
    int green;
    int blue;
}t_color;


typedef struct s_player
{
    double pos_x;
    double pos_y;
    char direction;
} t_player;


// 関数プロトタイプ
int check_map_file(char *arg, bool cub);

// マップ解析
t_map *parse_map(char *map_path);
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

void print_map(t_map *map);

#endif
