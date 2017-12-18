/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:13 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/18 19:44:12 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include <wolf.h>
# include <ray.h>

# define TEXT_WIDTH 64
# define TEXT_HEIGHT 64

# define WALL 2
# define WALL_BRICK 5
# define DIAMOND 6
# define GROUND 7
# define POMP 8
# define SECRET_PATH 9
# define SPRITES_TEXT 20
# define CHEST 21
# define DICKMAN 22
# define DICKMAN_B 23
# define DICKMAN_D 29
# define BARREL 24

# define NB_TEXTURES 30

typedef struct	s_text
{
	void		*text_ptr;
	int			*data;
	int			w;
	int			h;
	int			bpp;
	int			sl;
	int			edn;
}				t_text;

#endif
