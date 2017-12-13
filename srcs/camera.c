#include <camera.h>
#include <math.h>

/*
** init des vals de base de la cam
** xy en 2 pour pas poper dans un mur
*/

void			cam_init(t_cam *cam, double fov, int onlyfov)
{
	if (onlyfov == 0)
	{
		cam->pos_x = 3;
		cam->pos_y = 3;
		cam->fov = 0;
	}
	cam->fov += fov;
	if (cam->fov < 10)
		cam->fov = 10;
	if (cam->fov > 170)
		cam->fov = 170;
	cam->dir_x = 1;
	cam->dir_y = 0;
	cam->delta_x = 0;
	cam->delta_y = tan((cam->fov * 3.14 / 180.0) / 2);
}

/*
** action lorsque on appuy sur W
** on recup la position du joueur
** puis si le joueur se trouve sur un bloc vide 0 il se deplace
*/

void			cam_forward(t_cam *cam, t_map *map, double speed)
{
	int x;
	int y;

	x = (int)(cam->pos_x + cam->dir_x * speed);
	y = (int)(cam->pos_y + cam->dir_y * speed);
	if (map_get(map, x, (int)cam->pos_y) == 0
		&& map_get(map, (int)cam->pos_x, y) == 0)
	{
		cam->pos_x += cam->dir_x * speed;
		cam->pos_y += cam->dir_y * speed;
	}
}

/*
** pareil ici mais dans l'autre sens lorsque appui sur S
*/

void			cam_backward(t_cam *cam, t_map *map, double speed)
{
	int x;
	int y;

	x = (int)(cam->pos_x - cam->dir_x * speed);
	y = (int)(cam->pos_y - cam->dir_y * speed);
	if (map_get(map, x, (int)cam->pos_y) == 0
		&& map_get(map, (int)cam->pos_x, y) == 0)
	{
		cam->pos_x -= cam->dir_x * speed;
		cam->pos_y -= cam->dir_y * speed;
	}
}

/*
** Ici on calcul un nouvel angle de camera (rotation) losque on appui sur D
*/

void			cam_right(t_cam *cam, double speed)
{
	double dir_x;
	double delta_x;

	dir_x = cam->dir_x;
	delta_x = cam->delta_x;
	cam->dir_x = cam->dir_x * cos(speed) - cam->dir_y * sin(speed);
	cam->dir_y = dir_x * sin(speed) + cam->dir_y * cos(speed);
	cam->delta_x = cam->delta_x * cos(speed) - cam->delta_y * sin(speed);
	cam->delta_y = delta_x * sin(speed) + cam->delta_y * cos(speed);
}

/*
** Pareil mais dans l'autre sens lorsque appui sur A
*/

void			cam_left(t_cam *cam, double speed)
{
	double dir_x;
	double delta_x;

	dir_x = cam->dir_x;
	delta_x = cam->delta_x;
	cam->dir_x = cam->dir_x * cos(-speed) - cam->dir_y * sin(-speed);
	cam->dir_y = dir_x * sin(-speed) + cam->dir_y * cos(-speed);
	cam->delta_x = cam->delta_x * cos(-speed) - cam->delta_y * sin(-speed);
	cam->delta_y = delta_x * sin(-speed) + cam->delta_y * cos(-speed);
}
