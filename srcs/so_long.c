#include "../include/so_long.h"

void	check_args(int argc, char **argv)
{
	int	pos;

	if (argc != 2)
		ft_error("Error\nThis programe take 1 argument '.ber'\n", NULL);
	pos = ft_strlen(argv[1]) - 4;
	if (ft_strcmp(&argv[1][pos], ".ber") != 0)
		ft_error("Error\nWrong file extension.\n", NULL);
}

int	on_destroy(t_mlx *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window.reference);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
	return (0);
}


void	draw_base_img(t_mlx *mlx_data)
{
	new_img(mlx_data->data.width * 32, (mlx_data->data.height * 32), mlx_data);
	put_img_to_img(mlx_data->base_img, mlx_data->sprites[BG], 0, 0);
	draw_wall(mlx_data);
	draw_player(mlx_data);
	mlx_put_image_to_window (mlx_data->mlx_ptr, mlx_data->window.reference, mlx_data->base_img.img_ptr, 32, 32);
}

int	on_keypress(int keysim, t_mlx *data)
{
	
	if (keysim == 65363)
	{
		destroy_image(data);
		draw_base_img(data);
	}
	printf("Pressed key: %d\n", keysim);
	return (0);
}

void	init_sprite(t_mlx *mlx_data)
{
	new_file_img("assets/7.xpm", mlx_data, BG);
	new_file_img("assets/Wall_map.xpm", mlx_data, WALL);
	new_file_img("assets/player.xpm", mlx_data, PLAYER);

}

int	main(int argc, char **argv)
{
	t_mlx	mlx_data;

	check_args(argc, argv);
	set_content(&mlx_data.data.content);
	set_map(&mlx_data.data, argv[1]);
	check_map(&mlx_data.data);
	init_backtracking(&mlx_data.data);
	new_window(&mlx_data, "So_long");
	draw_border(&mlx_data);
	init_sprite(&mlx_data);
	draw_base_img(&mlx_data);
	mlx_hook(mlx_data.window.reference, KeyPress, KeyPressMask, &on_keypress, &mlx_data);
	mlx_hook(mlx_data.window.reference, DestroyNotify, StructureNotifyMask, &on_destroy, &mlx_data);
	mlx_loop(mlx_data.mlx_ptr);
	
	//free_map(data.map);
	return (0);
}