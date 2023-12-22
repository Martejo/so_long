#include "../include/so_long.h"

int	ft_iscontent(t_data *data, char c)
{
	if (c != data->content.collect && c != data->content.empty
			&& c != data->content.exit && c != data->content.player
			&& c != data->content.wall)
		return (-1);
	return (1);
}

void	check_content(t_data *data)
{
	int	width;
	int	height;

	height = 0;
	while (data->map[height])
	{
		width = 0;
		while (data->map[height][width])
		{
			if (data->map[height][width] == data->content.collect)
				data->content.count_collect += 1;
			else if (data->map[height][width] == data->content.exit)
				data->content.count_exit += 1;
			else if (data->map[height][width] == data->content.player)
			{
				data->content.count_player += 1;
				data->coord_player.coord_p.width = width;
				data->coord_player.coord_p.height = height; 
			}
			if (!ft_iscontent(data, data->map[height][width]))
				ft_error("Error\nUnknown symbol.", data);
			width++;
		}
		height++;
	}
}

void	check_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if ((data->map[0][i] != data->content.wall) || (data->map[data->height - 1][i] != data->content.wall))
			ft_error("Error\nMap column not close.", data);
		i++;
	}
	i = 0;
	while (data->map[i])
	{
		if ((data->map[i][0] != data->content.wall) || (data->map[i][data->width - 1] != data->content.wall))
			ft_error("Error\nMap line not close.", data);
		i++;
	}
}

void	check_format(t_data *data)
{
	int	width;
	int	height;
	int	count_x;

	
	height = 0;
	count_x = 0;
	while (data->map[0][count_x])
		count_x++;
	while (data->map[height])
	{
		width = 0;
		while (data->map[height][width])
			width++;
		if (width != count_x)
			ft_error("Error\nMap must be a rectangle.", data);
		height++;
	}
	if (height == count_x)
		ft_error("Error\nMap must be a rectangle.", data);
	data->height = height;
	data->width = count_x;
}

