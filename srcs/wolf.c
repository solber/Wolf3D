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
** on fou le pixel de couleur au bon endroit (decallage binaire pour recup le g et r)
*/

void			img_put_px(t_env *env, unsigned long color, int x, int y) //why unsigned long ?? => int
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
	//int		color;
	int		y;

	y = 0;
	//useless with floor_casting
	/*while (y < env->height - 1)
	{
		color = 0x14E4FF;
		if (y > env->height / 2)
			color = 0x838585;
		img_put_px(env, color, x, y);
		y++;
	}*/
	cur_pos = (double)x / (double)env->width;
	ray_init(&(env->ray), &(env->cam), cur_pos);
	ray_side_dist(&(env->ray));
	ray_dda(&(env->ray), &(env->map), 0);
	env->z_buffer[x] = env->ray.wall_dist; // set le buffer pour la distance des murs
	ray_display(env, &(env->ray), x, env->height);
	floor_casting(env, &(env->ray), x);
}

/*debug*/

void	print_buffer(double *z_buffer)
{
	for (int i = 0; i < WIDTH; i++)
	{
		printf("%.2f ||", z_buffer[i]);
	}
}

/*
** a mettre ailleurs, fonction de draw du fusil
** amelioration possible : une grosse partie de l'image est verte, donc on peut skipper tout ca
*/

void			draw_gun(t_env *env, t_text texture)
{
	int x;
	int y;
	int x_start;
	int y_start;

	y = -1;
	x_start = env->width / 2 - texture.w / 2;
	y_start = env->height - texture.h;
	while (++y < texture.h)
	{
		x = -1;
		while (++x < texture.w)
		{
			if (texture.data[x + y * texture.w] != 0xFF00)
				img_put_px(env, texture.data[x + y * texture.w], x + x_start, y + y_start);
		}
	}
}

/*
** fonction draw (autrefois a l'interieur d'exposehook)
*/

void			draw_all(t_env *env)
{
	int	x;

	x = -1;
	while (++x < env->width)
		vertical_draw(env, x);
	input_action(env);
	sprite_casting(env, &(env->cam));
	draw_gun(env, env->textures[POMP]);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img, 0, 0);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, 0xFFFFFF, "Points:");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 10, 0xFFFFFF, ft_itoa(env->map.coin)); // free !
	env->timer.delta -= 1;
	env->timer.ticks++;
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
	//map_init(&(env->map), filename);
	//init_sprites(&(env->sprites), env->nb_sprite);
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
			mlx_hook(env->win_ptr, 2, 1, key_hook_press, 0);
			mlx_hook(env->win_ptr, 3, 2, key_hook_release, 0);
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
