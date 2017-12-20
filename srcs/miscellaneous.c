/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:10:18 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/20 11:14:49 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "update.h"

void		update_game(t_env *env)
{
	int i;

	i = -1;
	while (++i < env->nb_sprite)
	{
		move_sprite(&(env->map), &(env->sprites[i]));
		if (env->sprites[i].timer_dead > 0)
			dying_animation(env, &(env->sprites[i]));
	}
	env->timer.ticks = 0;
	env->timer.timer = 0;
}
