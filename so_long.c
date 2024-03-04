/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:49:55 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/05 00:44:39 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_mlx *mlx)
{

	return (0);
	if (keycode == 53)
		close_map(mlx);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		// destory_img(mlx);// Destruction des anciennes images avant le déplacement du joueur pour la mise à jour
		// move_u_d_l_r(mlx, keycode);//deplacement du joueur en fonction de la touche pressée
		// initialize(mlx);//reintialisation de l interface graphique
		print_img(mlx->map, *mlx);//affichage du jeu
	}
	return (0);
}

int main (int ac, char **av)
{
	char	**two_d;
	t_mlx	mlx;

	two_d = parse_maps(ac, av, &mlx);
	print_img(two_d, mlx);

	mlx_hook(mlx.win_p, ON_KEYPRESS, (1LL<<0), move, &mlx);

	mlx_loop(mlx.mlx_p);

	return (0);
}

