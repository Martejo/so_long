MLX_FLAGS = -L minilibx-linux -lmlx_Linux -lmlx -lXext -lX11

INCLUDES = -I include -I libft/

SRCS = srcs/error.c \
		srcs/map.c \
		srcs/settings.c \
		srcs/check_map.c \
		srcs/so_long.c \
		srcs/utils.c \


OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(MLX_FLAGS) -Llibft -lft

%.o: %.c include/so_long.h libft/libft.h
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(INCLUDES_MXL) -c $< -o $@

clean:
	rm $(OBJS)

fclean:
	rm $(NAME)

.PHONY: all clean fclean

