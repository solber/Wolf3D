/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:41:13 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/14 15:19:29 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include <wolf.h>
# include <ray.h>

# define TEXT_WIDTH 64
# define TEXT_HEIGHT 64

# define NB_TEXTURES 9

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
