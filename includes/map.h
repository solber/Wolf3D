#ifndef MAP_H
# define MAP_H

# include <fcntl.h>

typedef struct	s_map
{
	int 		w;
	int 		h;
	int 		fd;
	int 		hited_obj_x;
	int 		hited_obj_y;
	int 		coin;
	int			*data;
}				t_map;

void			map_init(t_map *map, char *filename);
int				map_get(t_map *map, int x, int y);
int				map_color(int side);
void 			ft_open(t_map *map, char *filename);
void			ft_get_size(t_map *map);
void			ft_get_tex(t_map *map);
void 			ft_set_map(t_map *map);

//debug
void			print_map(t_map map);
#endif
