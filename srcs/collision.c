#include <camera.h>
#include <wolf.h>


static void add_coin(t_map *map)
{
	map->coin++;
	ft_putstr("coin : ");
	ft_putnbr(map->coin);
	ft_putchar('\n');
	system("afplay sounds/sfx_point.wav &");
	del_sprite(map, map->hited_obj_x + map->hited_obj_y * map->w);
}

int		check_collision(int texture_hited, t_map *map)
{
	//printf("texture_hited : %d\n", texture_hited);
	if (texture_hited == 0)
		return (1);
	if (texture_hited == SECRET_PATH)
		return (1);
	if (texture_hited == CHEST)
		add_coin(map);
	return (0);
}
