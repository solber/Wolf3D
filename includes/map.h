#ifndef MAP_H
# define MAP_H
# define MAP_WIDTH 12
# define MAP_HEIGHT 18

typedef struct	s_map
{
	int			data[MAP_WIDTH * MAP_HEIGHT];
}				t_map;

void			map_init(t_map *map);
int				map_get(t_map *map, int x, int y);
int				map_color(int side);

#endif
