/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:19:56 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/20 10:49:00 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>
#include <wolf.h>

static void	add_coin(t_map *map)
{
	map->coin++;
	ft_putstr("coin : ");
	ft_putnbr(map->coin);
	ft_putchar('\n');
	system("afplay sounds/sfx_point.wav &");
	del_sprite(map, map->hited_obj_x + map->hited_obj_y * map->w);
}

int			check_collision(int texture_hited, t_map *map)
{
	if (texture_hited == 0)
		return (1);
	if (texture_hited == SECRET_PATH)
		return (1);
	if (texture_hited == CHEST)
		add_coin(map);
	return (0);
}

/*
** gestion du kill, une seule fois pour eviter d'overkill Dickman
*/

void		check_kills(t_env *env)
{
	if (env->inputs.can_fire)
	{
		system("afplay sounds/shotgun.wav &");
		env->ray.hit_sprite = 0;
		ray_init(&(env->ray), &(env->cam), 0.5);
		ray_side_dist(&(env->ray));
		ray_dda(&(env->ray), &(env->map), 1);
		if (env->ray.hit_sprite == 1)
		{
			system("afplay sounds/death.wav &");
			env->ray.hit_sprite = 0;
			del_sprite(&(env->map),
			env->ray.map_x + env->ray.map_y * env->map.w);
		}
		env->inputs.can_fire = 0;
	}
}
