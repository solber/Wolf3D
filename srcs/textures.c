/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:10:22 by gmonnier          #+#    #+#             */
/*   Updated: 2017/12/18 19:43:19 by gmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>
#include <wolf.h>
#include <textures.h>

/*
** fonction generique pour load une texture et remplir la strucutre
*/

void		get_text(t_env *env, t_text *textures, char *path, int index)
{
	textures[index].text_ptr = mlx_xpm_file_to_image(env->mlx_ptr,
	path, &textures[index].w, &textures[index].h);
	textures[index].data = (int*)mlx_get_data_addr(textures[index].text_ptr,
	&textures[index].bpp, &textures[index].sl, &textures[index].edn);
}

/*
** Load toutes les textures, toutes les memes ici
*/

void			load_text(t_env *env, t_text *textures) // il faudra destroy les textures la fin du prog
{
	get_text(env, textures, "textures/wall.xpm", WALL);
	get_text(env, textures, "textures/gmonnier.xpm", 3);
	get_text(env, textures, "textures/wnoth.xpm", 4);
	get_text(env, textures, "textures/wall_brick.xpm", WALL_BRICK);
	get_text(env, textures, "textures/diamond.xpm", DIAMOND);
	get_text(env, textures, "textures/ground.xpm", GROUND);
	get_text(env, textures, "textures/diamond.xpm", SECRET_PATH);
	get_text(env, textures, "textures/chest.xpm", CHEST);
	get_text(env, textures, "textures/dickman.xpm", DICKMAN);
	get_text(env, textures, "textures/dickman_B.xpm", DICKMAN_B);
	get_text(env, textures, "textures/dickman_d.xpm", DICKMAN_D);
	get_text(env, textures, "textures/barrel.xpm", BARREL);
	get_text(env, textures, "textures/pomp_idle.xpm", POMP);
}

/*
** recupere la bonne texture de la map a afficher PUIS
** recupere ou la texture est touchee en x
** on connait la hauteur de la line a dessinee, on recupere les pixels
** correspondant et on store dans img
*/

/*
** on peut ajouter un effet plus sombre ici
*/

int		get_pixel_from_texture(t_env *env, t_ray *ray)
{
	int text_index;
	int color;

	text_index = env->map.data[ray->map_y * env->map.w + ray->map_x];
	color = env->textures[text_index].data[TEXT_HEIGHT * ray->tex_y + ray->tex_x];
	if (color == 0xFF00)
		return (0xFF00);
	//assombri les couleurs pour side == 1 (modifiable)
	if (ray->side > 1)
		return ((color >> 1) & 0x7F7F7F);
	return (color);
}

void	get_tex_x(t_ray *ray)
{
	int		tex_x;

	//valeur exacte ou la ray a touchee la texture
	if (ray->side <= 1)
		ray->wall_x = ray->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = ray->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);

	//pixel correspondant sur la texture
	tex_x = (int)(ray->wall_x * (double)(TEXT_WIDTH));
	if (ray->side <= 1 && ray->dir_x > 0)
		tex_x = TEXT_WIDTH - tex_x - 1;
	if (ray->side > 1 && ray->dir_y < 0)
		tex_x = TEXT_WIDTH - tex_x - 1;
	ray->tex_x = tex_x;
}

void	get_tex_y(t_ray *ray, int y, int height, int line_height)
{
	int d;

	d = y * 256 - height * 128 + line_height * 128;
	ray->tex_y = ((d * TEXT_HEIGHT) / line_height) / 256;
}
