#ifndef RAY_H
# define RAY_H
# include "camera.h"
# include "map.h"
# include <math.h>

typedef struct	s_ray
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_x;
	double		side_y;
	double		delta_x;
	double		delta_y;
	double		wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int 		tex_x;
	int 		tex_y;
	int			end; // jusqu'ou on doit draw la ray en vertical
	double		wall_x; //valeur exacte ou la ray a touchee la texture
	double		floor_x_wall;
	double		floor_y_wall; //x et y de la texture du sol en dessous de la ray
	int			floor_text_x;
	int			floor_text_y;
	int			hit_sprite; //check si la ray a touche un sprite avant un mur
}				t_ray;

void			ray_init(t_ray *ray, t_cam *camera, double cur_pos);
void			ray_side_dist(t_ray *ray);
void			ray_dda(t_ray *ray, t_map *map, int kill_sprites);

#endif
