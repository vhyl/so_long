#ifndef SO_LONG_H
#define SO_LONG_H
#define WIDTH 512
#define HEIGHT 512

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>

#include "../.mlx42/include/MLX42/MLX42.h"
#include "../libft/header/libft.h"

int valid_chars(char *s);
int count_char(char *s, char c);
int valid_map(char *s);
int get_height(char **s);
int get_lenght(char **s);
int valid_walls(char **s);
void find_player(char **map, int *x, int *y);
int valid_path(char **map);
void flood_fill(int x, int y, char **map);
char **create_map(char const *str, char c);
char *read_input(char *file_name);

#endif