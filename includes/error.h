/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:16:48 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/20 11:32:07 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <libft.h>
# include <wolf.h>

# define MAPS map->splited

void	checkforletter(t_map *map);
void	ft_check_for_error(t_map *map);
void	ft_continue_error(t_map *map);
void	ft_check_for_map_size(t_map *map);
void	ft_exit_line(int error, int linenb);
void	ft_getspawn(t_map *map);
void	check_y_zero(t_map *map);
void	check_x(t_map *map);

#endif
