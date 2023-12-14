#ifndef SO_LONG_H
#define SO_LONG_H

# include "../libft/libft.h"
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

typedef struct s_data
{
	t_content	content;
	t_pos_player	player;
	char	**map;
	int		height; //hauteur
	int		width; //largeur

}	t_data;
/*****Settings*****/
void	set_content(t_content *content);

/*****Error*****/
void	ft_error(char *msg, t_data *data);

/*****Map*****/
char	*get_map(int fd);
void	free_map(char **map);
void	set_map(t_data *data, char *file);
void	check_map(t_data *data);
bool	backtracking(t_data *data, int *exit, int *stuff, int x, int y);
//bool backtracking(t_data *data, int exit, int stuff, int x, int y, bool **visited);

/*****Check_Map*****/
void	check_wall(t_data *data);
void	check_format(t_data *data);
void	check_content(t_data *data);

#endif