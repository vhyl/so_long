#include "../header/so_long.h"

int valid_chars(char *s)
{ 
    while (*s)
    {
        if (*s != '0' && *s != '1' && *s != 'C' && *s != 'E' && *s != 'P' && *s != '\n')
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
    int x;

    x = 0;
    while (s[x])
        x++;

    return (x);
}

int get_lenght(char **s)
{
    int y;

    y = 0;
    while (s[0][y])
        y++;

    return (y);
}

int valid_walls(char **s)
{
    int i;
    int height;
    int length;


    i = 0;
    length = get_lenght(s) - 1;
    height = get_height(s) - 1;
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
    while (map[i])
    {
        j = 0;
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
    int x;
    int y;
    
    if (!valid_walls(map))
    {   
        find_player(map, &x, &y);
        flood_fill(x, y, map);
        x = 0;
        while (map[x])
        {
            y = 0;
            while (map[x][y])
            {
                if (map[x][y] != '1' && map[x][y] != 'x')
                    return (1);
                y++;
            }
            x++;
        }
    }
    return (0);
}

int check(char *s)
{
    char *str;
	char **map;

	str = read_input(s);

	if (!valid_map(str))
	{
		map = create_map(str, '\n');
        free(str);
		if (valid_path(map));
            return (0);
	}
    else 
        return (0);
    return (1);
}