#include <wolf.h>

/*
** malloc de la struct, creation du la window et de l'image puis appel aux init cam et map
** si on fail le malloc ou que !action on free lenv
*/

t_env			*ft_use_env(int action, char *filename)
{
	static t_env		*env;

	if (action == 1 || action == 2 || action == 3) // a changer?
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
			env->tmp = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->edn);
			load_text(env, env->textures);
			map_init(&(env->map), filename);
			init_sprites(&(env->sprites), env->nb_sprite);
			cam_init(&(env->cam), 66, 0);
			env->inputs.can_fire = 1;
			timer_init(&(env->timer));
			env->is_alive = 1;
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
** ici on itere pour draw ligne par ligne, expose_hook btw gere le drag and drop de la fenetre
** apres avoir tous draw, on balance l'image
*/

int				expose_hook(void *param)
{
	t_env		*env;

	env = ft_use_env(-1, 0);
	param = 0;
	if (env && env->is_alive == 1)
	{
		get_next_time(&(env->timer));
		//draw que quand necessaire pour avoir 60fps;
		if (env->timer.delta >= 1)
			draw_all(env);
		//updategame every 1/10 seconde
		if (env->timer.timer >= CLOCKS_PER_SEC / 10)
		{
			update_game(env);
			//print_map(env->map);
		}
		// possibilite d'afficher les fps sur l'ecran
		/*if (env->timer.timer >= CLOCKS_PER_SEC)
		{
			printf("FPS : %d\n", env->timer.ticks);
			env->timer.ticks = 0;
			env->timer.timer = 0;
			print_map(env->map);
		}*/
	}
	return (0);
}

/*a revoir*/

void			reset(t_env *env)
{
	env->is_alive = 1;
	printf("reset\n");
	env->map.initial_map = (int*)ft_memcpy(env->map.initial_map, env->map.reset_map, (env->map.w * env->map.h) * sizeof(int));
	env->map.data = (int*)ft_memcpy(env->map.data, env->map.reset_map, (env->map.w * env->map.h) * sizeof(int));
	free(env->sprites);
	free(env->sprites_order);
	free(env->sprites_distance);
	init_sprites(&(env->sprites), env->nb_sprite);
	cam_init(&(env->cam), 66, 0);
	env->inputs.left = 0;
	env->inputs.right = 0;
	env->inputs.up = 0;
	env->inputs.down = 0;
	env->inputs.sleft = 0;
	env->inputs.sright = 0;
	env->inputs.can_fire = 1;
	env->map.coin = 0;
	timer_init(&(env->timer));
	env->is_alive = 1;
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
			mlx_hook(env->win_ptr, KeyPress, KeyPressMask, key_hook_press, 0);
			mlx_hook(env->win_ptr, KeyRelease, KeyReleaseMask, key_hook_release, 0);
			mlx_hook(env->win_ptr, 17, 0, exit_hook, 0);
			mlx_expose_hook(env->win_ptr, expose_hook, 0);
			mlx_loop_hook(env->mlx_ptr, expose_hook, 0);
			system("afplay sounds/bg_music.mp3 &");
			mlx_loop(env->mlx_ptr);
		}
	}
	ft_putstr("Usage : wolf3d <map>\n");
	ft_use_env(0, 0);
	return (0);
}
