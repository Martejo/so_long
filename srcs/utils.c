/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:53:52 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/15 10:30:42 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] )
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

int	cpy_map(t_data *data, t_backtrack *data2)
{
	int		i;

	i = 0;
	data2->cpy_map = (char **)malloc((data->height + 1) * sizeof(char *));
	if (!data2->cpy_map)
		return (-1);
	while (i < data->height)
	{
		data2->cpy_map[i] = ft_strdup(data->map[i]);
		if (!data2->cpy_map[i])
			return (-1);
		i++;
	}
	data2->cpy_map[i] = NULL;
	return (1);
}