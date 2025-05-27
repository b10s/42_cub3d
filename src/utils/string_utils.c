#include "../../includes/cub3d.h"

bool is_empty_line(char *line)
{
    if (!line)
        return (true);
        
    for (int i = 0; line[i]; i++)
    {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return (false);
    }
    return (true);
}

void free_split(char **split)
{
    if (!split)
        return;
    for (int i = 0; split[i]; i++)
        free(split[i]);
    free(split);
}

char *trim_whitespace(char *str)
{
    if (!str)
        return (NULL);
        
    // 先頭の空白をスキップ
    char *start = str;
    while (*start && (*start == ' ' || *start == '\t'))
        start++;
        
    // 文字列が空白のみの場合
    if (*start == '\0')
        return (strdup(""));
        
    // 末尾の空白を見つける
    char *end = start + strlen(start) - 1;
    while (end > start && (*end == ' ' || *end == '\t'))
        end--;
        
    // 新しい文字列を作成
    int len = end - start + 1;
    char *result = malloc(len + 1);
    if (!result)
        return (NULL);
        
    strncpy(result, start, len);
    result[len] = '\0';
    
    return (result);
}
