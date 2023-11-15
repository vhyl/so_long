#include "../header/so_long.h"

int valid_chars(char *s)
{
    while (*s)
    {
        if (*s != '0' && *s != '1' && *s != 'C' && *s != 'E' && *s != 'P')
            return (1); // return 1 on wrong map
        s++;
    }
    return (0);
}

int count_char(char *s, char c)
{
    int count;

    count = 0;
    while (*s)
    {
        if (*s == c)
            count++;
        s++;
    }
    return (count);
}

int valid_map(char *s)
{
    if (count_char(s, 'E') > 1 || count_char(s, 'P') > 1)
    {
        ft_printf("Error\nThe map contains duplicate characters for (exit/start)\n");
        return (1);
    }
    if (count_char(s, 'C') < 1)
    {
        ft_printf("Error\nThe map contains less than 1 collectibles");
        return (1);
    }
    if (count_char(s, 'E') != 1 || count_char(s, 'P') != 1)
    {
        ft_printf("Error\nThere is fewer characters for (exit/start)");
        return (1);
    }
    if (valid_chars(s))
    {
        ft_printf("Error\nMap contains characters that are not allowed");
        return (1);
    }
    return (0);
}

int get_height(char **s)
{
    int x
}
int valid_walls(char **s)
{
    int i;

    i = 0;
    while (i < length)
    {
        if (s[0][i] != '1' || s[height][i] != '1')
            return (1);
        i++;
    }
    i = 0;
    while (i < height)
    {
        if (s[i][0] != '1' || s[i][length] != '1')
            return (1);
        i++;
    }
    return (0);
}

void find_player(char **map, int *x, int *y)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        while(map[i][j])
        {
            if (map[i][j] == 'P')
            {
                *x = i;
                *y = j;
                return ;
            }
            j++;
        }
        i++;
    }
}
int valid_path(char **map)
{
    if (valid_walls(map))
    
    flood_fill(x, y, map);

}