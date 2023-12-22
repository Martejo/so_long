/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:23:42 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/19 15:25:19 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

enum {
	BORDER = 0,
	WALL = 1,
	PLAYER = 2,
	BG = 3,
};

typedef struct s_vector
{
	int	width;
	int	height;
	int	vy; //vitesse verticale
	int	gravity;
}				t_vector;

typedef struct s_window
{
	void	*reference;
	t_vector	size;
}	t_window;

typedef struct s_image
{
	void		*img_ptr;
	char		*addr;
	t_vector	size;
	int			bpp; //bits_per_pixel;
	int			endian;
	int			line_len;
}		t_image;

typedef struct s_backtrack
{
	char	**cpy_map;
	int		exit;
	int		stuff;
	int		count_collect;
	int		width;
	int		height;

}	t_backtrack;

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

typedef struct s_player
{
	t_vector coord_p;
}	t_player;

typedef struct s_data
{
	t_content	content;
	t_player	coord_player;
	char	**map;
	int		height; //hauteur
	int		width; //largeur

}	t_data;

typedef struct s_mlx
{
	void		*mlx_ptr;
	t_window	window;
	t_data		data;
	t_image		base_img;
	t_image		sprites[6];
}	t_mlx;


#endif