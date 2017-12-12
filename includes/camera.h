#ifndef CAMERA_H
# define CAMERA_H
# include "map.h"

typedef struct	s_cam
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		delta_x;
	double		delta_y;
	double		fov;
}				t_cam;

void			cam_init(t_cam *cam, double fov, int onlyfov);
void			cam_forward(t_cam *cam, t_map *map, double speed);
void			cam_backward(t_cam *cam, t_map *map, double speed);
void			cam_right(t_cam *cam, double speed);
void			cam_left(t_cam *cam, double speed);

#endif
