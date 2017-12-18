/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:51:45 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/18 17:05:31 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "update.h"

void		timer_init(t_timer *timer)
{
	timer->last_time = clock();
	timer->delta = 0;
	timer->timer = 0;
	timer->ticks = 0;
}

void		get_next_time(t_timer *timer)
{
	timer->time_per_tick = CLOCKS_PER_SEC / FPS;
	timer->now = clock();
	timer->delta += (timer->now - timer->last_time) / timer->time_per_tick;
	timer->timer += timer->now - timer->last_time;
	timer->last_time = timer->now;
}

void		move_sprite(t_map *map, t_sprite *sprite)
{
	int save_x;
	int avoid_wall;

	if ((sprite->text_index == DICKMAN || sprite->text_index == DICKMAN_B) && sprite->del == 0)
	{
		save_x = (int)sprite->x;
		//update map
		if ((sprite->x + sprite->dir_x) - save_x >= 1 ||
		(sprite->x + sprite->dir_x) - save_x <= 0) // si on change de case
		{
			avoid_wall = sprite->dir_x > 0 ? 1 : -1;
			if (map_get(map, (int)(sprite->x + sprite->dir_x + avoid_wall), (int)sprite->y) > 0) // si le sprite rentre dans un mur
			{
				sprite->dir_x = -sprite->dir_x; // on change de sens
				sprite->text_index = sprite->dir_x > 0 ? DICKMAN_B : DICKMAN;
			}
			// on met a jour la map
			map->initial_map[(int)sprite->y * map->w + save_x] = 0;
			map->initial_map[(int)sprite->y * map->w + (int)(sprite->x + sprite->dir_x)] = sprite->text_index;
		}
		sprite->x += sprite->dir_x;
	}
}

void		update_game(t_env *env)
{
	int i;

	i = -1;
	while (++i < env->nb_sprite)
	{
		move_sprite(&(env->map), &(env->sprites[i]));
	}
	//printf("FPS : %d\n", env->timer.ticks * 10);
	env->timer.ticks = 0;
	env->timer.timer = 0;
	//print_map(env->map);
}
