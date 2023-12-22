#ifndef SO_LONG_H
#define SO_LONG_H

# include "struct.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "X11/keysym.h"
# include "X11/X.h"
# include "../minilibx-linux/mlx_int.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>

/*****Settings*****/
void	set_content(t_content *content);

/*****Error*****/
void	ft_error(char *msg, t_data *data);

/*****Map*****/
char	*get_map(int fd);
void	set_map(t_data *data, char *file);
void	check_map(t_data *data);
//bool	backtracking(t_backtrack *data, int x, int y);
void	init_backtracking(t_data *data);
//bool backtracking(t_data *data, int exit, int stuff, int x, int y, bool **visited);

/*****Check_Map*****/
void	check_wall(t_data *data);
void	check_format(t_data *data);
void	check_content(t_data *data);

/*****Utils*****/
int	cpy_map(t_data *data, t_backtrack *data2);
void	free_map(char **map);

/******Window_utils*****/
void	destroy_image(t_mlx	*mlx_data);
void	new_window(t_mlx *mlx_data, char *str);

/******Image_utils*****/
void	put_img_to_img(t_image dest, t_image src, int width, int height);
unsigned int	get_pixel_img(t_image image, int width, int height);
void	put_pixel_img(t_image image, int width, int height, int color);
void	new_img(int width, int height, t_mlx *mlx_data);
void	new_file_img(char *path, t_mlx *mlx_data, int sprite);

void	draw_border(t_mlx *mlx_data);
void	draw_wall(t_mlx *mlx_data);
void	draw_player(t_mlx *mlx_data);
void	draw_base_img(t_mlx *mlx_data);
int	ft_input(int keysim, t_mlx *mlx_data);
int	on_destroy(t_mlx *data);


#endif