/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:10:18 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/20 11:26:23 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "update.h"
#include <inputs.h>

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

/*
** exit propre lorsque ESC appuye // DEVRA AUSSI GERER LES FREES !
*/

int				exit_hook(void *param)
{
	t_env *env;

	env = ft_use_env(-1, 0);
	param = 0;
	destroy_text(env, env->textures);
	mlx_destroy_image(env->mlx_ptr, env->img);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	free(env->sprites);
	free(env->sprites_order);
	free(env->sprites_distance);
	if (env->map.data)
		free(env->map.data);
	if (env->map.initial_map)
		free(env->map.initial_map);
	if (env->map.reset_map)
		free(env->map.reset_map);
	ft_use_env(0, 0);
	system("killall afplay");
	exit(EXIT_SUCCESS);
}
