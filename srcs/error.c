#include "../include/so_long.h"

void	ft_error(char *msg, t_data *data)
{
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	if (data)
	{
		if (data->map)
			free_map(data->map);
	}
	exit(EXIT_FAILURE);
}