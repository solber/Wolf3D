/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:28:08 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/14 12:32:12 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	get_floor_coord(t_ray *ray)
{
	// 4 ray->sides possibles...je comprends pas trop ce qu'il se passe ici....
	// a adapter car on a 4 valeurs de ray->side possibles
	if (ray->side <= 1 && ray->dir_x > 0)
	{
		ray->floor_x_wall = ray->map_x;
		ray->floor_y_wall = ray->map_y + ray->wall_x;
	}
	else if (ray->side <= 1 && ray->dir_x < 0)
	{
		ray->floor_x_wall = ray->map_x + 1.0;
		ray->floor_y_wall = ray->map_y + ray->wall_x;
	}
	else if (ray->side > 1 && ray->dir_y > 0)
	{
		ray->floor_x_wall = ray->map_x + ray->wall_x;
		ray->floor_y_wall = ray->map_y;
	}
	else
	{
		ray->floor_x_wall = ray->map_x + ray->wall_x;
		ray->floor_y_wall = ray->map_y + 1.0;
	}
}

void		floor_casting(t_env *env, t_ray *ray, int pos)
{
	double	dist_player;
	double	current_dist;
	double	weight;
	double	current_floor_x;
	double	current_floor_y;
	int		y;

	get_floor_coord(ray);
	dist_player = 0.0;

	//protection si jamais ray->end a overflow un int
	if (ray->end < 0) ray->end = env->height;
	//printf("ray end : %d\n", ray->end);
	//on imprime le floor depuis end, jusqu'au bas
	y = ray->end;
	while (++y < env->height)
	{
		//mathematiques obscures
		current_dist = env->height / (2.0 * y - env->height);
		weight = (current_dist - dist_player) / (ray->wall_dist - dist_player);
		current_floor_x = weight * ray->floor_x_wall + (1.0 - weight) * ray->pos_x;
		current_floor_y = weight * ray->floor_y_wall + (1.0 - weight) * ray->pos_y;

		ray->floor_text_x = (int)(current_floor_x * TEXT_WIDTH) % TEXT_WIDTH;
		ray->floor_text_y = (int)(current_floor_y * TEXT_HEIGHT) % TEXT_HEIGHT;
		//floor
		//decalage binaire pour le rendre plus fonce
		img_put_px(env, (env->textures[7].data[TEXT_WIDTH * ray->floor_text_y + ray->floor_text_x] >> 1) & 0x7F7F7F, pos, y);
		//ceiling (symmetrical!)
		img_put_px(env, env->textures[7].data[TEXT_WIDTH * ray->floor_text_y + ray->floor_text_x], pos, env->height - y);
	}
}
