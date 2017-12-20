/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:00:57 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/20 11:19:55 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"
#include "wolf.h"
#include "textures.h"

/*
 ** fonction basique de tri des sprites selon leur distance
*/

void		sort_sprites(int *order, double *dist, int nb)
{
	int		i;
	int		count;
	int		tmp;
	double	tmp2;

	count = 0;
	while (count < nb)
	{
		i = 0;
		while (i < nb - 1)
		{
			if (dist[i] < dist[i + 1])
			{
				tmp = order[i];
				order[i] = order[i + 1];
				order[i + 1] = tmp;
				tmp2 = dist[i];
				dist[i] = dist[i + 1];
				dist[i + 1] = tmp2;
			}
			i++;
		}
		count++;
	}
}

void		del_sprite(t_map *map, int pos)
{
	t_env	*env;
	int		i;

	env = ft_use_env(-1, 0);
	i = -1;
	while (++i < env->nb_sprite)
	{
		if ((int)env->sprites[i].y * map->w + (int)env->sprites[i].x == pos)
		{
			if (env->sprites[i].type == DICKMAN)
				env->sprites[i].timer_dead = 10;
			else
				env->sprites[i].del = 1;
			map->initial_map[pos] = 0;
		}
	}
}
