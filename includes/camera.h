#ifndef CAMERA_H
# define CAMERA_H
# include "map.h"

# define SPEED_ROT 0.10
# define SPEED_MOVE 0.15

typedef struct	s_cam
{
	double		pos_x; // position dans la map
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		delta_x;
	double		delta_y;
	double		fov;
}				t_cam;

void			cam_init(t_cam *cam, double fov, int onlyfov);
void			cam_right(t_cam *cam, double speed);
void			cam_forward(t_cam *cam, t_map *map, double speed);
void			cam_backward(t_cam *cam, t_map *map, double speed);
void			cam_left(t_cam *cam, double speed);
int				get_collision(int x, int y, t_map *map);
int				check_collision(int texture_hited, t_map *map);
#endif
