#include "../include/so_long.h"

char	*get_map(int fd)
{
	char	*map;
	char	*buffer;
	char	*map_tmp;

	map = ft_calloc(1, 1);
	buffer = ft_calloc(1, 1);
	while (buffer)
	{
		free(buffer);
		buffer = NULL;
		buffer = get_next_line(fd);
		if (errno)
		{
			free(map);
			ft_error(strerror(errno), NULL);
		}
		if (buffer)
		{
			map_tmp = ft_strjoin(map, buffer);
			free(map);
			map = map_tmp;
		}
	}
	return (map);
}

void	set_map(t_data *data, char *file)
{
	int		fd;
	char	*map_tmp;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_error(strerror(errno), NULL);
	map_tmp = get_map(fd);
	data->map = ft_split(map_tmp, '\n');
	free(map_tmp);
	if (!data->map)
		ft_error("Error\nSplit failure.", NULL);
}

void	check_map(t_data *data)
{
	check_format(data);
	check_wall(data);
	check_content(data);
	if (data->content.count_exit != 1 || data->content.count_player != 1
				|| data->content.count_collect == 0)
		ft_error("Error\nNeed one Player, exit and some collectables.", data);
}

bool	backtracking(t_backtrack *data, int x, int y)
{

	if (data->stuff == data->count_collect && data->exit == 1)
		return (true);
	if (data->cpy_map[x][y] == '1')
		return (false);
	if (data->cpy_map[x][y] == 'C')
		data->stuff++;
	if (data->cpy_map[x][y] == 'E')
		data->exit++;
	data->cpy_map[x][y] = '1'; //Marquer la position
	if (backtracking(data, x - 1, y))
		return (true);
	if (backtracking(data, x, y - 1))
		return (true);
	if (backtracking(data, x + 1, y))
		return (true);
	if (backtracking(data, x, y + 1))
		return (true);
	// data->map[x][y] = tmp;
	// write(1, "A\n", 2);

	return (false);
}

void	init_backtracking(t_data *data)
{
	t_backtrack data_backtrack;
	
	if (!cpy_map(data, &data_backtrack))
	{
		free_map(data_backtrack.cpy_map);
		ft_error("Error Malloc\n", data);
	}
	data_backtrack.exit = 0;
	data_backtrack.stuff = 0;
	data_backtrack.count_collect = data->content.count_collect;
	if (!backtracking(&data_backtrack, data->player.col_player, data->player.line_player))
	{
		free_map(data_backtrack.cpy_map);
		ft_error("Error\nThe map must be solvable.", data);
	}
	free_map(data_backtrack.cpy_map);
}
