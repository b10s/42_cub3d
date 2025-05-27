#include "../../includes/cub3d.h"

bool find_player_position(char **grid, t_player *player)
{
    for (int i = 0; grid[i]; i++)
    {
        for (int j = 0; grid[i][j]; j++)
        {
            char c = grid[i][j];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                player->x = j + 0.5;  // セルの中央
                player->y = i + 0.5;
                player->direction = c;
                
                // マップ上のプレイヤー文字を空のスペースに変更
                grid[i][j] = '0';
                return (true);
            }
        }
    }
    return (false);
}