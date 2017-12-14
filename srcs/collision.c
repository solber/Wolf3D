#include <camera.h>
#include <wolf.h>

static void add_coin(t_map *map)
{
	map->coin++;
	ft_putstr("coin : ");
	ft_putnbr(map->coin);
	ft_putchar('\n');
	system("afplay sounds/sfx_point.wav &");
	//ft_putstr("BEFORE : ");
	//ft_putnbr(map_get(map, map->hited_obj_x, map->hited_obj_y));
	map->data[map->hited_obj_x + map->hited_obj_y * map->w] = 0;
	//ft_putchar('\n');
	//ft_putstr("AFTER : ");
	//ft_putnbr(map_get(map, map->hited_obj_x, map->hited_obj_y));
	//ft_putchar('\n');
	//print_map(*map);
}

int		get_collision(int x, int y, t_map *map)
{
	if (x == 0 && y == 0)
		return (1);
	if (x == 8 || y == 8)
		add_coin(map);
	if (x == 9 || y == 9)
		return (1);
	return (0);
}
