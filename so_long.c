/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:49:55 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/04 22:07:49 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
	char	**two_d;
	t_mlx	mlx;

	two_d = parse_maps(ac, av, &mlx);
	print_img(two_d, mlx);

	mlx_hook(mlx.win_p, ON_KEYUP, 0, hook, &mlx);

	mlx_loop(mlx.mlx_p);

	return (0);
}

	// mlx_hook(mlx.win_p, ON_KEYDOWN, 0, mlx.win_p);
	// mlx_hook(mlx.win_p, ON_KEYUP, 0, );