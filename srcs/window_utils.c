#include "../include/so_long.h"

void	new_window(t_mlx *mlx_data, char *str)
{

	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		ft_error("Error\nMlx_init fail.", &mlx_data->data);
	mlx_data->window.reference = mlx_new_window(mlx_data->mlx_ptr, (mlx_data->data.width * 32) + 64, (mlx_data->data.height * 32) + 64, str);
	mlx_data->window.size.width = (mlx_data->data.width * 32) + 64;
	mlx_data->window.size.height = (mlx_data->data.height * 32) + 64;
	if (!mlx_data->window.reference)
	{
		free(mlx_data->mlx_ptr);
		ft_error("Error\nMlx_new_window.", &mlx_data->data);
	}
}

void	destroy_image(t_mlx	*mlx_data)
{
	if (mlx_data->base_img.img_ptr && mlx_data->mlx_ptr)
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->base_img.img_ptr);
}