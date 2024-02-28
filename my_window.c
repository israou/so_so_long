/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:21:01 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/28 18:46:04 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*mlx_the_window(t_mlx *mlx)
{
	int		height;
	int		width;


	height = mlx->height;
	width = mlx->width;
	mlx->mlx_p = mlx_init();
	mlx = mlx_new_window(mlx->mlx_p, 1000, 1000, "SO_LONG");
	if (!mlx)
		errors("Error for window\n", 2);
	mlx_loop(mlx->mlx_p);
	return (mlx);
}