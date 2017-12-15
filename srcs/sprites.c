/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:12:05 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/15 12:53:14 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"
#include "wolf.h"
#include "textures.h"

void		init_sprites(t_sprite *sprites)
{
	sprites[0].x = 4.5;
	sprites[0].y = 9.5;
	sprites[0].text_index = 8;
}

void		sprite_casting(t_env *env, t_cam *cam)
{
	// sort
	//static int i = 0;
	//translate sprite position relative to camera
	double sprite_x;
	double sprite_y;
	double inv_det; //??
	t_text current_text;

	current_text = env->textures[env->sprites[0].text_index];
	sprite_x = env->sprites[0].x - cam->pos_x;
	sprite_y = env->sprites[0].y - cam->pos_y;

	//printf("%d\n", i);
	//i++;
	//printf("sprite_x : %f, sprite_y : %f\n", sprite_x, sprite_y);
	inv_det = 1.0 / (cam->delta_x * cam->dir_y - cam->dir_x * cam->delta_y); // for matrix multi

	double transform_x;
	double transform_y;

	transform_x = inv_det * (cam->dir_y * sprite_x - cam->dir_x * sprite_y); // profondeur du sprite
	transform_y = inv_det * (-cam->delta_y * sprite_x + cam->delta_x * sprite_y);

	int sprite_screen_x = (int)((WIDTH / 2) * (1 + transform_x / transform_y));

	// calcul de la hauteur du sprites
	int sprite_height = abs((int)(HEIGHT / transform_y));
	//premier et dernier pixel de la bande
	int draw_start_y = -sprite_height / 2 + HEIGHT / 2;
	if (draw_start_y < 0)
		draw_start_y = 0;
	int draw_end_y = sprite_height / 2 + HEIGHT / 2;
	if (draw_end_y >= HEIGHT)
		draw_end_y = HEIGHT - 1;

	//calcul la largeur du sprite
	int sprite_width = abs((int)(HEIGHT / transform_y)); // pourquoi y ??
	int draw_start_x = -sprite_width / 2 + sprite_screen_x;
	if (draw_start_x < 0)
		draw_start_x = 0;
	int draw_end_x = sprite_width / 2 + sprite_screen_x;
	if (draw_end_x >= WIDTH)
		draw_end_x = WIDTH - 1;

	//printf("draw_start_x : %d, draw_end_x : %d\n", draw_start_x, draw_end_x);
	//printf("draw_start_y : %d, draw_end_y : %d\n", draw_start_y, draw_end_y);
	// boucle pour chaque bande du sprite
	for (int stripe = draw_start_x; stripe < draw_end_x; stripe++)
	{
		int tex_x = (int)(256 * (stripe - (-sprite_width / 2 + sprite_screen_x)) * TEXT_WIDTH / sprite_width) / 256;
		//conditions pour draw :
		// iteration en y pour chaque bande
		if (transform_y > 0 && stripe > 0 && stripe < WIDTH && transform_y < env->z_buffer[stripe])
		{
			for (int y = draw_start_y; y < draw_end_y; y++)
			{
				int d = y * 256 - HEIGHT * 128 + sprite_height * 128;
				int tex_y = ((d * TEXT_HEIGHT) / sprite_height) / 256;
				int color = env->textures[env->sprites[0].text_index].data[tex_y * TEXT_WIDTH + tex_x];
				int color = current_text.data[tex_y * TEXT_WIDTH + tex_x];
				//printf("%#x\n", color);
				if (color != 0xFF00)
					img_put_px(env, color, stripe, y);
			}
		}
	}
}
