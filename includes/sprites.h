/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:10:37 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/15 10:30:19 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# define NB_SPRITES 1

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				text_index;
}					t_sprite;

void		init_sprites(t_sprite *sprites);

#endif
