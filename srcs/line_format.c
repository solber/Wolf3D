#include <error.h>
#include <wolf.h>

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
