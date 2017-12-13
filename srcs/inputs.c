#include "wolf.h"

/*
** exit propre lorsque ESC appuye
*/

int				exit_hook(void *param)
{
	param = 0;
	ft_use_env(0, 0);
	system("killall afplay");
	exit(1);
}

/*
** ici on fait les deplacement en appelant une autre fonction pour le keyrepeat
** ici faut juste prendre en compte qu'on ce deplace ou qu'on rotate de notre variable speedmv, ou speedrot
** Pour strafer on fait une douille astral, c'est a dire qu'on fait regarder un court instant
** vers la direction du straf, puis on avance, puis on regarde dans le sens inverse
** ce qui donne l'impression plutot reussi de straf
*/

void			input_action(t_env *env)
{
	double speedmv = 0.15;
	double speedrot = 0.10;
	if (env->inputs.left == 1)
		cam_left(&(env->cam), speedrot);
	if (env->inputs.right == 1)
		cam_right(&(env->cam), speedrot);
	if (env->inputs.up == 1)
		cam_forward(&(env->cam), &(env->map), speedmv);
	if (env->inputs.down == 1)
		cam_backward(&(env->cam), &(env->map), speedmv);
	if (env->inputs.sleft == 1)
	{
		cam_left(&(env->cam), 1.57);
		cam_forward(&(env->cam), &(env->map), 0.10);
		cam_left(&(env->cam), -1.57);
	}
	if (env->inputs.sright == 1)
	{
		cam_right(&(env->cam), 1.57);
		cam_forward(&(env->cam), &(env->map), 0.10);
		cam_right(&(env->cam), -1.57);
	}
}

/*
** ici on change juste le FOV (Field Of View = Champ de vision)
** en gros plus c'est haut plus on vois les choses plates.
*/

static void		key_hook_press_cam(t_env *env, int keycode)
{
	if (env != 0 && keycode == FOVUP)
		cam_init(&(env->cam), 1, 1);
	if (env != 0 && keycode == FOVDOWN)
		cam_init(&(env->cam), -1, 1);
}

/*
** ici on gere juste le keypress en repeat
*/

int				key_hook_press(int keycode, void *param)
{
	t_env		*env;

	env = ft_use_env(-1, 0);
	param = 0;
	if (keycode == 53)
		exit_hook(param);
	if (env != 0 && keycode == FORWARD)
		env->inputs.up = 1;
	if (env != 0 && keycode == BACKWARD)
		env->inputs.down = 1;
	if (env != 0 && keycode == LEFT)
		env->inputs.left = 1;
	if (env != 0 && keycode == RIGHT)
		env->inputs.right = 1;
	if (env != 0 && keycode == STRAFL)
		env->inputs.sleft = 1;
	if (env != 0 && keycode == STRAFR)
		env->inputs.sright = 1;
	key_hook_press_cam(env, keycode);
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

/*
** et icio on gere juste quand on release pour arreter la boucle sur les actions
*/

int				key_hook_release(int keycode, void *param)
{
	t_env		*env;

	env = ft_use_env(-1, 0);
	param = 0;
	if (env != 0 && keycode == FORWARD)
		env->inputs.up = 0;
	if (env != 0 && keycode == BACKWARD)
		env->inputs.down = 0;
	if (env != 0 && keycode == LEFT)
		env->inputs.left = 0;
	if (env != 0 && keycode == RIGHT)
		env->inputs.right = 0;
	if (env != 0 && keycode == STRAFL)
		env->inputs.sleft = 0;
	if (env != 0 && keycode == STRAFR)
		env->inputs.sright = 0;
	return (0);
}
