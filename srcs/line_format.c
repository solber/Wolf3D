#include <error.h>
#include <map.h>
#include <wolf.h>

#include <stdio.h>

void 	check_y_zero(t_map *map)
{
	int i;

	i = 0;
	while (i < map->h)
	{
		if (map_get(map, 0, i) != 2)
			ft_exit(7);
		if (map_get(map, map->w - 1, i) != 2)
			ft_exit(8);
		i++;
	}
	i = 0;
	while (i < map->w)
	{
		if (map_get(map, i, map->h - 1) != 2)
			ft_exit(9);
		i++;
	}
}

void	check_x(t_map *map)
{
	int max;
	int i;

	i = 0;
	max = 0;
	map->linenb++;
	map->splited = ft_strsplit(map->line, ' ');
	checkforletter(map);
	ft_putendl(map->line);
	while (map->splited[i])
	{
		if (ft_atoi(map->splited[i]) < 0)
			ft_exit_line(5, map->linenb);
		max++;
		i++;
	}
	if (max != map->w)
		ft_exit_line(4, map->linenb);
}

void	ft_getspawn(t_map *map)
{
	int i;// h
	int j;// w
	int spawned = 0;
	t_env *env;

	env = ft_use_env(-1, 0);
	i = 0;
	j = 0;
	while (j < map->w && !spawned)
	{
		i = 0;
		while (i < map->h)
		{
			if (j > 0 && map_get(map, j, i) == 0)
			{
				env->cam.pos_x = j + 0.5;
				env->cam.pos_y = i + 0.5;
				spawned = 1;
				break;
			}
			i++;
		}
		j++;
	}
	if (!spawned)
		ft_exit(6);
}