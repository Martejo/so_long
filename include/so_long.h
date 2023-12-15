#ifndef SO_LONG_H
#define SO_LONG_H

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

//Contient les chrs de la map


typedef struct s_content
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	empty;
	int		count_player;
	int		count_exit;
	int		count_collect;
}	t_content;

typedef struct s_pos_player
{
	int	col_player; //width
	int	line_player; //height
}	t_pos_player;

typedef struct s_backtrack
{
	char	**cpy_map;
	int		exit;
	int		stuff;
	int		count_collect;

}	t_backtrack;

typedef struct s_data
{
	t_content	content;
	t_pos_player	player;
	char	**map;
	int		height; //hauteur
	int		width; //largeur

}	t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*texture[5];
}	t_mlx;

/*****Settings*****/
void	set_content(t_content *content);

/*****Error*****/
void	ft_error(char *msg, t_data *data);

/*****Map*****/
char	*get_map(int fd);
void	set_map(t_data *data, char *file);
void	check_map(t_data *data);
bool	backtracking(t_backtrack *data, int x, int y);
void	init_backtracking(t_data *data);
//bool backtracking(t_data *data, int exit, int stuff, int x, int y, bool **visited);

/*****Check_Map*****/
void	check_wall(t_data *data);
void	check_format(t_data *data);
void	check_content(t_data *data);

/*****Utils*****/
int	cpy_map(t_data *data, t_backtrack *data2);
void	free_map(char **map);

#endif