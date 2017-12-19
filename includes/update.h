/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonnier <gmonnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:51:58 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/18 14:59:35 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "wolf.h"

typedef struct		s_timer
{
	clock_t			now;
	clock_t			last_time;
	double			delta;
	clock_t			timer;
	int				ticks;
	double			time_per_tick;
}					t_timer;

#endif
