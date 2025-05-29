#include "parse.h"

static int color_to_int(t_color *color)
{
    return ((color->red << 16) | (color->green << 8) | color->blue);
}

bool parse_rgb_to_color(char *rgb_str, t_color *color)
{
 // RGB値を取得
 char **rgb = ft_split(rgb_str, ',');
 if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
 {
     free_split(rgb);
     free_split(rgb);
     return (false);
 }

    // 数値に変換
    color->red = ft_atoi(rgb[0]);
     color->green = ft_atoi(rgb[1]);
 color->blue = ft_atoi(rgb[2]);

    // 値の範囲チェック (0-255)
    if (color->red < 0 || color->red > 255 || 
        color->green < 0 || color->green > 255 || 
        color->blue < 0 || color->blue > 255)
    {
        free_split(rgb);
        return (false);
    }
    
    free_split(rgb);
    return (true);
}

bool parse_color(t_map *map, char *line)
{
    char **split = ft_split(line, ' ');
    if (!split || !split[0] || !split[1] || split[2])
    {
        free_split(split);
        return (false);
    }
    t_color color;
    if (!parse_rgb_to_color(split[1], &color))
    {
        free_split(split);
        return (false);
    }

  // 色を保存
    if (ft_strncmp(split[0], "F", 1) == 0)
    {   
    if (map->floor_color != -1)  // 重複チェック
    {
          free_split(split);
          return (false);
      }
      map->floor_color = color_to_int(&color);
  }
  else if (ft_strncmp(split[0], "C", 1) == 0)
  {
      if (map->ceiling_color != -1)  // 重複チェック
      {
          free_split(split);
          return (false);
      }
      map->ceiling_color = color_to_int(&color);
  }
  else
  {
      free_split(split);
      return (false);
  }
  
  free_split(split);
  return (true);
}