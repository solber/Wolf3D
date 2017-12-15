#include <camera.h>
#include <wolf.h>

//moche
void		del_sprite(t_map *map)
{
	t_env *env;
	int i;

	env = ft_use_env(-1, 0);
	i = -1;
	while (++i < env->nb_sprite)
	{
		if ((env->sprites[i].y - 0.5) * map->w + (env->sprites[i].x - 0.5) ==
		map->hited_obj_x + map->hited_obj_y * map->w)
		{
			env->sprites[i].del = 1;
		}
	}
}


static void add_coin(t_map *map)
{
	map->coin++;
	ft_putstr("coin : ");
	ft_putnbr(map->coin);
	ft_putchar('\n');
	system("afplay sounds/sfx_point.wav &");
	map->initial_map[map->hited_obj_x + map->hited_obj_y * map->w] = 0;
	del_sprite(map);
}

/*int		get_collision(int x, int y, t_map *map)
{
	if (x == 0 && y == 0)
		return (1);
	if (x == 8 || y == 8)
		add_coin(map);
	if (x == 9 || y == 9)
		return (1);
	return (0);
}*/

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
