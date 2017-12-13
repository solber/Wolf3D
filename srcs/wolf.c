#include <wolf.h>

/*
** malloc de la struct, creation du la window et de l'image puis appel aux init cam et map
** si on fail le malloc ou que !action on free lenv
*/

t_env			*ft_use_env(int action, char *filename)
{
	static t_env		*env;

	if (action == 1 || action == 2 || action == 3)
	{
		env = (t_env*)ft_memalloc(sizeof(t_env));
		if (env != 0)
		{
			env->width = WIDTH;
			env->height = HEIGHT;
			env->mlx_ptr = mlx_init();
			env->win_ptr = mlx_new_window(env->mlx_ptr, env->width,
				env->height, "Wolf3D");
			env->img = mlx_new_image(env->mlx_ptr, env->width, env->height);
			load_text(env, env->textures);
			map_init(&(env->map), filename);
			cam_init(&(env->cam), 66, 0);
		}
		else
			action = 0;
	}
	if (action == 0 && env != 0)
	{
		ft_memdel((void**)&(env));
	}
	return (env);
}

/*
** on fou le pixel de couleur au bon endroit (decallage binaire pour recup le g et r)
*/

void			img_put_px(t_env *env, unsigned long color, int x, int y)
{
	env->tmp[y * env->sl + x * env->bpp / 8] = (color & 0xFF);
	env->tmp[y * env->sl + x * env->bpp / 8 + 1] = (color & 0xFF00) >> 8;
	env->tmp[y * env->sl + x * env->bpp / 8 + 2] = (color & 0xFF0000) >> 16;
}

/*
** ici on draw une colonne a la fois , avec gestion ciel et sol
** 
*/

static void		vertical_draw(t_env *env, int x)
{
	double	cur_pos;
	int		color;
	int		y;

	y = 0;
	while (y < env->height - 1)
	{
		color = 0x14E4FF;
		if (y > env->height / 2)
			color = 0x838585;
		img_put_px(env, color, x, y);
		y++;
	}
	cur_pos = (double)x / (double)env->width;
	ray_init(&(env->ray), &(env->cam), cur_pos);
	ray_side_dist(&(env->ray));
	ray_dda(&(env->ray), &(env->map), !env->inputs.wall);
	ray_display(env, &(env->ray), x, env->height);
}

/*
** ici on itere pour draw ligne par ligne, expose_hook btw gere le drag and drop de la fenetre
** apres avoir tous draw, on balance l'image
*/

int				expose_hook(void *param)
{
	t_env		*env;
	int			x;

	env = ft_use_env(-1, 0);
	param = 0;
	if (env)
	{
		env->tmp = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->edn);
		x = 0;
		while (x < env->width)
		{
			vertical_draw(env, x);
			x++;
		}
		input_action(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
	}
	return (0);
}

/*
** on lance l'image , et on lance les hook.
*/

int				main(int argc, char **argv)
{
	t_env		*env;

	env = 0;
	if (argc == 2 && argv[1])
	{
		env = ft_use_env(1, argv[1]);
		if (env != 0 && env->mlx_ptr != 0)
		{
			mlx_hook(env->win_ptr, 2, 1, key_hook_press, 0);
			mlx_hook(env->win_ptr, 3, 2, key_hook_release, 0);
			mlx_hook(env->win_ptr, 17, 0, exit_hook, 0);
			mlx_expose_hook(env->win_ptr, expose_hook, 0);
			mlx_loop_hook(env->mlx_ptr, expose_hook, 0);
			system("afplay sounds/song.mp3 &");
			mlx_loop(env->mlx_ptr);
		}
	}
	ft_putstr("Usage : wolf3d <map>\n");
	ft_use_env(0, 0);
	return (0);
}
