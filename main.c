
#include "./parse/parse.h"

/**
 * メイン関数 - プログラムのエントリーポイント
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return (1);
    }

    t_map *map = parse_map(argv[1]);
    if (map == NULL)
    {
        fprintf(stderr, "Failed to parse map\n");
        return (1);
    }

    print_map(map);
    // 必要なら free_map(map) をここで呼び出してメモリ解放
    return (0);
}
