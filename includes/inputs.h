#ifndef INPUTS_H
# define INPUTS_H

#ifdef __linux__

# define FORWARD 119
# define BACKWARD 115
# define LEFT 97
# define RIGHT 100
# define STRAFL 113
# define STRAFR 101
# define FIRE 32

# define FOVUP 65451
# define FOVDOWN 65453

#else
# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define STRAFL 12
# define STRAFR 14

# define FOVUP 69
# define FOVDOWN 78

# define FIRE 49
#endif

typedef struct	s_inputs
{
	int			left;
	int			right;
	int			up;
	int			down;
	int			sleft;
	int			sright;
	//int			wall; //useless now
	int			fire;
	int			can_fire;
}				t_inputs;

int				key_hook_press(int keycode, void *param);
int				key_hook_release(int keycode, void *param);
int				exit_hook(void *param);

#endif
