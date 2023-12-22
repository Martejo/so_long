/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartel <gemartel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:05:45 by gemartel          #+#    #+#             */
/*   Updated: 2023/12/19 16:30:38 by gemartel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_move(int keysim, t_vector *vector_player)
{
	if (keysim == 65363)//droite
		vector_player->width++;
	else if (keysim == 65361) //gauche
		vector_player->width--;

}

void	update_position(t_mlx *mlx_data, t_vector player)
{
	mlx_data->data.map[player.height][player.width] = 'P';
	mlx_data->data.map[mlx_data->data.coord_player.coord_p.height][mlx_data->data.coord_player.coord_p.width] = '0';
	mlx_data->data.coord_player.coord_p = player;
}

	

int	ft_input(int keysim, t_mlx *mlx_data)
{
	

	t_vector tmp;

	if (keysim == XK_Escape)
		on_destroy(mlx_data);
	if ((keysim != XK_Left && keysim != XK_Right 
			&& keysim != XK_Up && keysim != XK_Down)) // Rajouter condition de victoire
		return (0);
	tmp = mlx_data->data.coord_player.coord_p;
	if (keysim == XK_Left || keysim == XK_Right)
		update_move(keysim, &tmp);
	else if (keysim == XK_Up && mlx_data->data.map[tmp.height + 1][tmp.width] == '1')
		tmp.vy = (mlx_data->data.height / 3) * -1;
	if (mlx_data->data.coord_player.coord_p.gravity == 1)
	{
		tmp.height++;
	}
	else if (tmp.vy < 0 || mlx_data->data.coord_player.coord_p.vy < 0)
		tmp.height--;
	if (mlx_data->data.map[tmp.height][tmp.width] == 'C')
		mlx_data->data.content.count_collect--;
	if (mlx_data->data.map[tmp.height][tmp.width] == '1' ||
		(mlx_data->data.map[tmp.height][tmp.width] == 'E' && mlx_data->data.content.count_collect > 0))
	{
		mlx_data->data.coord_player.coord_p.gravity = 0;
		return (0);
	}
	update_position(mlx_data, tmp);
	printf("keysim = %d\n", keysim);
	draw_base_img(mlx_data);
	return (0);
}

/*int ft_input(int keysim, t_mlx *mlx_data)
{
    t_vector *player = &mlx_data->data.coord_player.coord_p;

    if (keysim == XK_Escape)
        on_destroy(mlx_data);

    // Mise à jour de la position horizontale
    if (keysim == XK_Left || keysim == XK_Right)
        update_move(keysim, player);

    // Gestion du saut
    if (keysim == XK_Up && mlx_data->data.map[player->height + 1][player->width] == '1')
	{
        player->vy = (mlx_data->data.height / 3) * -1;
    }

    // Appliquer la gravité à chaque itération
    player->vy += player->gravity; // Assurez-vous que player->gravity est initialisé correctement

    // Mise à jour de la position verticale
    player->height += player->vy;

    // Vérifier les collisions avec le sol
    if (player->vy > 0 && mlx_data->data.map[player->height][player->width] == '1')
	{
        player->vy = 0;
        //player->height = 5;  ajuster à la position juste au-dessus du sol 
    }

    // Autres vérifications de collision et mise à jour de la position
    // ...

    draw_base_img(mlx_data);

    return (0);
}*/

