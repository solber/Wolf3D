NAME=wolf3d
SRC= srcs/inputs.c \
	srcs/map.c \
	srcs/ray.c \
	srcs/camera.c \
	srcs/wolf.c \
	srcs/parse.c \
	srcs/textures.c \
	srcs/floor_casting.c \
	srcs/collision.c \
	srcs/sprites.c \
	srcs/update.c \
	srcs/error.c \
	srcs/line_format.c

CC=clang
CFLAGS=-I libft/includes -I minilibx_macos/ -I get_next_line/ -I includes/ -Wall -Wextra -Werror
OBJ=$(SRC:.c=.o)
LDFLAGS=-L libft/ -L minilibx_macos/
LIBS=-lft -lm -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBS)

all: $(NAME)

clean:
	make -C libft/ clean
	make -C minilibx_macos/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@
