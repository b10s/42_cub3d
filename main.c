
#include "./parse/parse.h"

/**
 * メイン関数 - プログラムのエントリーポイント
 */
int main(int argc, char **argv)
{
    t_map *map;

    if (argc != 2)
    {
        printf("Usage: %s <map file>\n", argv[0]);
        return (1);
    }

    map = parse_map(argv[1]);
    if (!map)
        return (1);

    print_map(map);

    free_map(map);
    free(map);
    return (0);
}
