MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/x11 -lXext -lx11

INCLUDES_MXL = -I/usr/include -Imlx

SRCS = srcs/error.c \
		srcs/map.c \
		srcs/settings.c \
		srcs/check_map.c \
		srcs/so_long.c \


OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -Iinclude -Ilibft $(OBJS) -o $(NAME) -Llibft -lft

%.o: %.c include/so_long.h libft/libft.h
	@$(CC) $(CFLAGS) -Iinclude -Ilibft -c $< -o $@

clean:
	rm $(OBJS)

fclean:
	rm $(NAME)

.PHONY: all clean fclean

