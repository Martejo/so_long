#include "../include/so_long.h"

void	new_img(int width, int height, t_mlx *mlx_data)
{
	mlx_data->base_img.img_ptr = mlx_new_image(mlx_data->mlx_ptr, width, height);
	mlx_data->base_img.addr = mlx_get_data_addr(mlx_data->base_img.img_ptr, &mlx_data->base_img.bpp,
			&mlx_data->base_img.line_len, &mlx_data->base_img.endian);
	mlx_data->base_img.size.width = width;
	mlx_data->base_img.size.height = height;
}

void	new_file_img(char *path, t_mlx *mlx_data, int sprite)
{
	
	mlx_data->sprites[sprite].img_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr, path, &mlx_data->sprites[sprite].size.width,
										&mlx_data->sprites[sprite].size.height);
	
	if (!mlx_data->sprites[sprite].img_ptr)
		write(2, "File could not be read\n", 23);
	else
		mlx_data->sprites[sprite].addr = mlx_get_data_addr(mlx_data->sprites[sprite].img_ptr, &mlx_data->sprites[sprite].bpp,
				&mlx_data->sprites[sprite].line_len, &mlx_data->sprites[sprite].endian);
}

void	put_pixel_img(t_image image, int width, int height, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (width >= 0 && height >= 0 && width < image.size.width && height < image.size.height)
	{
		dst = image.addr + (height * image.line_len + width * (image.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_image image, int width, int height)
{
	return (*(unsigned int*)((image.addr + (height * image.line_len) + (width * image.bpp / 8))));
}

void	put_img_to_img(t_image dest, t_image src, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.size.width)
	{
		j = 0;
		while (j < src.size.height)
		{
			put_pixel_img(dest, width + i, height + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}