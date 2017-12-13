#include <map.h>
#include <wolf.h>
/*
** ici on define une map et on remplis notre struct map avec cette derniere
** FF = bloc plein, 00 bloc vide, 02 un mur, 01 un bloc vide bloquant le joueur
*/

void 			ft_exit(int error)
{
	ft_use_env(0, 0);
	if (error == 1)
		ft_putendl("Error : Can't malloc map.");
	else if (error == 2)
		ft_putendl("Error : Can't open file.");
	else if (error == 3)
		ft_putendl("Error : Incorrect map size.");
	exit(-1);
}

void			map_init(t_map *map, char *filename)
{
	ft_open(map, filename);
	ft_get_size(map);
	if (!(map->data = (int *)malloc(sizeof(int) * (map->w * map->h))))
		ft_exit(1);
	ft_set_map(map);
}

/*
** On parcour le tableau pour renvoyer ca valeur 
*/

int				map_get(t_map *map, int x, int y)
{
	int		pos;

	if (map != 0 && x < map->w)
	{
		pos = x + (y * map->w);
		if (pos >= 0 && pos < (map->w * map->h))
		{
			return (map->data[pos]);
		}
	}
	return (0xffffff);
}

/*
** on renvoi la couleur en fonction de l'orientation
*/

int				map_color(int side)
{
	if (side == 1)
		return (0xFF0000);
	if (side == 2)
		return (0x002FFF);
	if (side == 3)
		return (0x0DFF00);
	return (0xFFEE00);
}
