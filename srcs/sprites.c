/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:12:05 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/19 14:00:17 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"
#include "wolf.h"
#include "textures.h"

void		init_sprites(t_sprite **sprites, int nb)
{
	t_env *env;
	int i;
	int index;

	env = ft_use_env(-1, 0);
	*sprites = (t_sprite*)ft_memalloc(sizeof(t_sprite) * nb); //il faudra free
	env->sprites_order = (int*)ft_memalloc(sizeof(int) * nb);
	env->sprites_distance = (double*)ft_memalloc(sizeof(double) * nb);

	i = -1;
	index = 0;
	while (++i < env->map.w * env->map.h)
	{
		if (env->map.data[i] >= SPRITES_TEXT)
		{
			(*sprites)[index].x = i % env->map.w + 0.5;
			(*sprites)[index].y = i / env->map.w + 0.5;
			(*sprites)[index].del = 0;
			(*sprites)[index].text_index = env->map.data[i];
			(*sprites)[index].dir_x = -SPRITE_SPEED;
			(*sprites)[index].type = env->map.data[i];
			(*sprites)[index].timer_dead = 0;
			//printf("%.2f, %.2f\n", (*sprites)[index].x, (*sprites)[index].y);
			//printf("%d\n", (*sprites)[index].text_index);
			env->map.data[i] = 0;
			index++;
		}
	}
}

static void		sprite_draw(t_env *env, t_sprite *sprite)
{
	int x;
	int y;
	int d;
	int color;

	x = sprite->draw_start_x;
	while (x < sprite->draw_end_x)
	{
		sprite->tex_x = (int)(256 * (x - (-sprite->width / 2 + sprite->screen_x)) * TEXT_WIDTH / sprite->width) / 256;
		if (sprite->transform_y > 0 && x > 0 && x < WIDTH && sprite->transform_y < env->z_buffer[x])
		{
			y = sprite->draw_start_y;
			while (y < sprite->draw_end_y)
			{
				d = y * 256 - HEIGHT * 128 + sprite->height * 128;
				sprite->tex_y = ((d * TEXT_HEIGHT) / sprite->height) / 256;
				color = env->textures[sprite->text_index].data[sprite->tex_y * TEXT_WIDTH + sprite->tex_x];
				if (color != 0xFF00)
					img_put_px(env, color, x, y);
				y++;
			}
		}
		x++;
	}
}

static void		sprite_calc(t_cam *cam, t_sprite *sprite)
{
	//variables de calculs intermediaires
	double inv_det;

	sprite->real_x = sprite->x - cam->pos_x;
	sprite->real_y = sprite->y - cam->pos_y;
	inv_det = 1.0 / (cam->delta_x * cam->dir_y - cam->dir_x * cam->delta_y); // for matrix multi
	sprite->transform_x = inv_det * (cam->dir_y * sprite->real_x - cam->dir_x * sprite->real_y); // profondeur du sprite
	sprite->transform_y = inv_det * (-cam->delta_y * sprite->real_x + cam->delta_x * sprite->real_y);
	sprite->screen_x = (int)((WIDTH / 2) * (1 + sprite->transform_x / sprite->transform_y));

	sprite->height = abs((int)(HEIGHT / sprite->transform_y));
	sprite->draw_start_y = -sprite->height / 2 + HEIGHT / 2;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->height / 2 + HEIGHT / 2;
	if (sprite->draw_end_y >= HEIGHT)
		sprite->draw_end_y = HEIGHT - 1;
	sprite->width = abs((int)(HEIGHT / sprite->transform_y)); // pourquoi y ??

	sprite->draw_start_x = -sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->width / 2 + sprite->screen_x;
	if (sprite->draw_end_x >= WIDTH)
		sprite->draw_end_x = WIDTH - 1;
}

void		sort_sprites(int *order, double *dist, int nb)
{
	int i;
	int count;
	int tmp;
	double tmp2;

	count = 0;
	while (count < nb)
	{
		i = 0;
		while (i < nb - 1)
		{
			if (dist[i] < dist[i + 1])
			{
				//printf("swap between : %f and %f\n", sprites[i].real_dist, sprites[i + 1].real_dist);
				//printf("%p and %p\n", &sprites[i], &sprites[i + 1]);
				//swap_ptr((void**)&dist[i], (void**)&dist[i + 1]);
				tmp = order[i];
				order[i] = order[i + 1];
				order[i + 1] = tmp;

				tmp2 = dist[i];
				dist[i] = dist[i + 1];
				dist[i + 1] = tmp2;
				//swap_ptr((void**)&sprites[i], (void**)&sprites[i + 1]);
			}
			i++;
		}
		count++;
	}
}



void		sprite_casting(t_env *env, t_cam *cam)
{
	int i; 

	//sort les sprites, de tel maniere qu on imprime les pres en dernier, donc devant les autres
	i = -1;
	while (++i < env->nb_sprite)
	{
		env->sprites_order[i] = i;
		//env->sprites[i].real_dist = ((cam->pos_x - env->sprites[i].x) * (cam->pos_x - env->sprites[i].x) + 
		//(cam->pos_y - env->sprites[i].y) * (cam->pos_y - env->sprites[i].y));
		env->sprites_distance[i] = ((cam->pos_x - env->sprites[i].x) * (cam->pos_x - env->sprites[i].x) + 
		(cam->pos_y - env->sprites[i].y) * (cam->pos_y - env->sprites[i].y));
		//gestion de la collision avec le perso
		if (env->sprites_distance[i] <= HIT_BOX && !env->sprites[i].del && 
		env->sprites[i].type == DICKMAN && env->sprites[i].timer_dead == 0)
			env->is_alive = 0;
	}
	sort_sprites(env->sprites_order, env->sprites_distance, env->nb_sprite);
	//boucle sur chaque sprite pour le dessiner
	i = -1;
	while (++i < env->nb_sprite)
	{
		// pour quand on effacera des sprites, on verif que y'en a bien un a dessiner
		if (env->sprites[env->sprites_order[i]].del == 0 && env->sprites[env->sprites_order[i]].text_index != 0)
		{
			sprite_calc(cam, &(env->sprites[env->sprites_order[i]]));
			sprite_draw(env, &(env->sprites[env->sprites_order[i]]));
		}
	}
}

void		del_sprite(t_map *map, int pos)
{
	t_env *env;
	int i;

	env = ft_use_env(-1, 0);
	i = -1;
	while (++i < env->nb_sprite)
	{
		if ((int)env->sprites[i].y * map->w + (int)env->sprites[i].x == pos)
		{
			//env->sprites[i].del = 1;
			if (env->sprites[i].type == DICKMAN)
				env->sprites[i].timer_dead = 10;
			else
				env->sprites[i].del = 1;
			map->initial_map[pos] = 0;
		}
	}
}

/*
** gestion du kill, une seule fois pour eviter d'overkill Dickman
*/

void		check_kills(t_env *env)
{
	if (env->inputs.can_fire)
	{
		system("afplay sounds/shotgun.wav &");
		printf("check_kills\n");
		env->ray.hit_sprite = 0;
		ray_init(&(env->ray), &(env->cam), 0.5);
		ray_side_dist(&(env->ray));
		ray_dda(&(env->ray), &(env->map), 1);
		if (env->ray.hit_sprite == 1)
		{
			system("afplay sounds/death.wav &");
			printf("OMG you've killed Dickman\n");
			env->ray.hit_sprite = 0;
			del_sprite(&(env->map), env->ray.map_x + env->ray.map_y * env->map.w);
		}
		env->inputs.can_fire = 0;
	}
}
