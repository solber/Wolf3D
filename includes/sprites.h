/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:10:37 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/15 16:22:56 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				text_index;
	double			real_x; //coordonnees par rapport au joueurs(camera)
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
}					t_sprite;
void		init_sprites(t_sprite **sprites, int nb);
#endif
