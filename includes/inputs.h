#ifndef INPUTS_H
# define INPUTS_H

# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define STRAFL 12
# define STRAFR 14

# define FOVUP 69
# define FOVDOWN 78

typedef struct	s_inputs
{
	int			left;
	int			right;
	int			up;
	int			down;
	int			sleft;
	int			sright;
	int			wall;
}				t_inputs;

int				key_hook_press(int keycode, void *param);
int				key_hook_release(int keycode, void *param);
int				exit_hook(void *param);

#endif
