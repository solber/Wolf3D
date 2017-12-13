#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <libft.h>
# include "inputs.h"
# include "camera.h"
# include "ray.h"

# define WIDTH 1200
# define HEIGHT 675

typedef struct	s_env
{
	int			width;
	int			height;
	void		*mlx_ptr;
	void		*win_ptr;
	int			bpp;
	int			sl;
	int			edn;
	int			*img;
	int 		*moiimg;
	int 		*moiimgdata;
	char		*tmp;
	t_inputs	inputs;
	t_cam		cam;
	t_ray		ray;
	t_map		map;
}				t_env;

t_env			*ft_use_env(int action, char *filename);
void			input_action(t_env *env);
int				expose_hook(void *param);
void			img_put_px(t_env *env, unsigned long color, int x, int y);
void			ray_display(t_env *env, t_ray *ray, int pos, int height);
void 			ft_exit(int error);

#endif
