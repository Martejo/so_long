MLX_FLAGS = -L minilibx-linux -lmlx_Linux -lmlx -lXext -lX11

INCLUDES = -I include -I libft/

SRCS = srcs/error.c \
		srcs/map.c \
		srcs/settings.c \
		srcs/check_map.c \
		srcs/so_long.c \
		srcs/utils.c \
		srcs/image_utils.c \
		srcs/window_utils.c \
		srcs/draw_game.c \
		srcs/gameplay.c \


OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -g3 $(INCLUDES) $(OBJS) -o $(NAME) $(MLX_FLAGS) -Llibft -lft

%.o: %.c include/*.h libft/libft.h
	@$(CC) $(CFLAGS) -g3 -Iinclude -Ilibft $(INCLUDES_MXL) -c $< -o $@

clean:
	rm $(OBJS)

fclean:
	rm $(NAME)

.PHONY: all clean fclean

