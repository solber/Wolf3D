#include <map.h>
#include <wolf.h>

void ft_open(t_map *map, char *filename)
{
	if (!(map->fd = open(filename, O_RDONLY)))
		ft_exit(2);
}

void ft_get_size(t_map *map)
{
	char 	**splited;
	char	*line;
	int 	count;

	count = 0;
	while (get_next_line(map->fd, &line))
	{
		if (count)
		{
			splited = ft_strsplit(line, ' ');
			map->w = ft_atoi(splited[0]);
			map->h = ft_atoi(splited[1]);
			free(splited);
			free(line);
			break;
		}

		if (line)
			free(line);
		count++;
	}
}

void ft_get_tex(t_map *map)
{
	t_env	*env;
	char	**splited;
	char	*line;
	int		count;

	count = 0;
	env = ft_use_env(-1, 0);
	while (get_next_line(map->fd, &line) && count <= 1)
	{
		if (count)
		{
			splited = ft_strsplit(line, ' ');
			env->floor = ft_atoi(splited[0]);
			env->roof = ft_atoi(splited[1]);
			free(splited);
		}		
		free(line);
		count++;
	}
}

void ft_set_map(t_map *map)
{
	char 	**splited;
	char 	*line;
	int 	count;
	int 	i;
	int 	j;

	count = 0;
	i = 0;
	j = 0;
	while (get_next_line(map->fd, &line) && count < map->h)
	{
		ft_putendl(line);
		splited = ft_strsplit(line, ' ');
		while (splited[j])
		{
			map->data[i] = ft_atoi(splited[j]);
			i++;
			j++;
		}
		j = 0;
		free(splited);
		if (line)
			free(line);
		count++;
	}
}
