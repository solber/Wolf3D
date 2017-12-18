/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:10:37 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/18 15:27:40 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# define SPRITE_SPEED 0.1

typedef struct		s_sprite
{
	double			x; //coordonnes dans la map
	double			y;
	double			dir_x; // vecteur de direction pour ceux qui bougent
	double			dir_y; // non utiliser en l'etat actuel
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
