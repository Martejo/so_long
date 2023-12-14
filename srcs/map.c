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

bool	backtracking(t_data *data, int *exit, int *stuff, int x, int y)
{
	char	tmp;

	printf("stuff = %d exit = %d\n", *stuff, *exit);
	if (*stuff == data->content.count_collect && *exit == 1)
		return (true);
	if (data->map[x][y] == '1')
		return (false);
	if (data->map[x][y] == 'C')
		(*stuff)++;
	if (data->map[x][y] == 'E')
		(*exit)++;
	tmp = data->map[x][y];
	// for(int i = 0; i < data->height; i++)
	// 	printf("%s\n", data->map[i]);
	// printf("\n");
	data->map[x][y] = '1'; //Marquer la position
	if (backtracking(data, exit, stuff, x - 1, y))
		return (true);
	if (backtracking(data, exit, stuff, x, y - 1))
		return (true);
	if (backtracking(data, exit, stuff, x + 1, y))
		return (true);
	if (backtracking(data, exit, stuff, x, y + 1))
	{
		return (true);
	}
	write(1, "A\n", 2);
	data->map[x][y] = tmp;
	return (false);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

