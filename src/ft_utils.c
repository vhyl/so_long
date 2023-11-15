#include "../header/so_long.h"

void flood_fill(int x, int y, char **map)
{
        if (map[x][y] != 'x' && map[x][y] != '1')
        {
            if (map[x][y] == '0' || map[x][y] == 'C' || map[x][y] == 'E' || map[x][y] == 'P')
                map[x][y] = 'x';
            flood_fill(x + 1, y, map);
            flood_fill(x - 1, y, map);
            flood_fill(x, y + 1, map);
            flood_fill(x, y - 1, map);
        }
}
 