/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:00:20 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/08 00:00:41 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		close_map();
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		move_u_d_l_r(mlx, keycode);
		print_img(mlx->map, *mlx);
		mlx->i = 0;
		mlx->j = 0;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**two_d;
	t_mlx	mlx;

	mlx.moves = 0;
	two_d = parse_maps(ac, av, &mlx);
	print_img(two_d, mlx);
	mlx_hook(mlx.win_p, ON_KEYPRESS, (1LL << 0), move, &mlx);
	mlx_hook(mlx.win_p, BOUTON_CLOSE, (1LL << 0), &close_map, &mlx);
	mlx_loop(mlx.mlx_p);
	return (0);
}
