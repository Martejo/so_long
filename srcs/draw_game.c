#include "../include/so_long.h"


void	draw_border(t_mlx *mlx_data)
{
	int		x;
	int		y;

	new_file_img("assets/WallBordure.xpm", mlx_data, BORDER);
	x = 0;
	y = 0;
	while (x < mlx_data->data.width * 32 + 64)
	{
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->window.reference, mlx_data->sprites[BORDER].img_ptr, x , 0);
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->window.reference, mlx_data->sprites[BORDER].img_ptr, x , (mlx_data->data.height * 32) + 32);
		x += 32;
	}
	while (y < (mlx_data->data.height * 32) + 64)
	{
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->window.reference, mlx_data->sprites[BORDER].img_ptr, 0 , y);
		mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->window.reference, mlx_data->sprites[BORDER].img_ptr, (mlx_data->data.width * 32) + 32 , y);
		y += 32;
	}
}

void	draw_player(t_mlx *mlx_data)
{
	mlx_data->data.player.line_player = mlx_data->data.height - 2;
	mlx_data->data.player.col_player++;
	put_img_to_img(mlx_data->base_img, mlx_data->sprites[PLAYER], mlx_data->data.player.col_player * 32, mlx_data->data.player.line_player * 32);

}
void	draw_wall(t_mlx *mlx_data)
{
	int	width;
	int	height;

	width = 1;
	height = 1;
	
	while (height < mlx_data->data.height - 1)
	{
		width = 1;
		while (width < mlx_data->data.width - 1)
		{
			if (mlx_data->data.map[height][width] == '1')
				put_img_to_img(mlx_data->base_img, mlx_data->sprites[WALL], width * 32, height * 32);
			width++;
		}
		height++;
	}
}