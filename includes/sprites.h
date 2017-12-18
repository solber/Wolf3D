/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:10:37 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/18 11:10:35 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				del; // pour savoir si on a recup le sprite, de base 0
	int				text_index;
	double			real_x; //coordonnees par rapport au joueur(camera)
	double			real_y;
	double			transform_x; //profondeur du sprite
	double			transform_y;
	int				tex_x; //pixels correspondant sur la texture
	int				tex_y;
	int				draw_start_y; // ou faut il draw
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				width;
	int				height;
	int				screen_x;
	double			real_dist;
}					t_sprite;
void		init_sprites(t_sprite **sprites, int nb);
#endif
