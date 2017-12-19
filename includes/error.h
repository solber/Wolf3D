#ifndef ERROR_H
# define ERROR_H

# include <libft.h>
# include <wolf.h>

//void	ft_check_for_letters(t_map *map);
void 	checkforletter(t_map *map);
void	ft_check_for_error(t_map *map);
void	ft_continue_error(t_map *map);
void	ft_check_for_map_size(t_map *map);
void 	ft_exit_line(int error, int linenb);
void	ft_getspawn(t_map *map);
void 	check_y_zero(t_map *map);

void	check_x(t_map *map);

#endif