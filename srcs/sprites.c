/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:12:05 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/15 15:57:12 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"
#include "wolf.h"
#include "textures.h"

void		init_sprites(t_sprite **sprites, int nb)
{
	*sprites = (t_sprite*)ft_memalloc(sizeof(t_sprite) * nb); //il faudra free

	(*sprites)[0].x = 9.5;
	(*sprites)[0].y = 3.5;
	(*sprites)[0].text_index = 8;
	(*sprites)[1].x = 10.5;
	(*sprites)[1].y = 3.5;
	(*sprites)[1].text_index = 10;
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

void		sprite_casting(t_env *env, t_cam *cam)
{
	int i; 

	//TO DO : sort_sprites
	
	//boucle sur chaque sprite pour le dessiner
	i = -1;
	while (++i < env->nb_sprite)
	{
		// pour quand on effacera des sprites, on verif que y'en a bien un a dessiner
		if (&(env->sprites[i]))
		{
			sprite_calc(cam, &(env->sprites[i]));
			sprite_draw(env, &(env->sprites[i]));
		}
	}
}
