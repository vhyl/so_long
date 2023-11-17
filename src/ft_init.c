#include "../header/so_long.h"

char *read_input(char *file_name)
{
	char *buff;
	char *res;
	int op;
	int size;

	op = open(file_name, O_RDONLY);
	size = 0;
	buff = malloc(sizeof(char));
	while (read(op, buff, 1))
		size++;
	close(op);
	op = open(file_name, O_RDONLY);
	res = malloc(sizeof(char) * size);
	read(op, res, size);
	free(buff);
	return (res);
}

char **create_map(char const *str, char c)
{
	char **map;

	map = ft_split(str , c);
	return (map);
}