/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:49:55 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/05 04:46:53 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_map(mlx);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		move_u_d_l_r(mlx, keycode);//deplacement du joueur en fonction de la touche pressée
		print_img(mlx->map, *mlx);//affichage du jeu
		mlx->i = 0;
		mlx->j = 0;
	}
	return (0);
}

void	r()
{
	system("leaks so_long");
}

int main (int ac, char **av)
{
	atexit(r);
	char	**two_d;
	t_mlx	mlx;

	two_d = parse_maps(ac, av, &mlx);
	print_img(two_d, mlx);
	mlx_hook(mlx.win_p, ON_KEYPRESS, (1LL<<0), move, &mlx);
	mlx_loop(mlx.mlx_p);
	return (0);
}

