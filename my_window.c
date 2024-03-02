/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:21:01 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/02 02:52:10 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_mlx *mlx_pointers)
{
	mlx_pointers->mlx_p = mlx_init();
	if (!mlx_pointers->mlx_p)
		errors("Error init connexion with graphical server\n", 2);
}

void	create_window(t_mlx *mlx_pointers)
{
	mlx_pointers->win_p = mlx_new_window(mlx_pointers->mlx_p, 1000, 1000, "SO_LONG");
	if (!mlx_pointers->win_p)
		errors("Error 4 window\n", 2);
}

void	load_and_display_image(t_mlx *mlx_pointers, char *filename, void **p)
{
	*p = mlx_xpm_file_to_image(mlx_pointers->mlx_p, filename, &(mlx_pointers->w), &(mlx_pointers->h));
	if (!*p)
		errors("Error loading XPM image\n", 2);
}

void	put_image(t_mlx *mlx, int i, int j, void *img)
{
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, img, j * 64, i * 64);
}

void	the_mlx(t_mlx *mlx_pointers)
{
	mlx_pointers->w = 0;
	mlx_pointers->h = 0;
	init_mlx(&mlx_pointers);
	create_window(&mlx_pointers);
	load_and_display_image(mlx_pointers, "galaxy.xpm", &(mlx_pointers->background));
	load_and_display_image(mlx_pointers, "collectibles.xpm", &(mlx_pointers->collect));
	load_and_display_image(mlx_pointers, "walll.xpm", &(mlx_pointers->wall));
	load_and_display_image(mlx_pointers, "p1.xpm", &(mlx_pointers->player));
	load_and_display_image(mlx_pointers, "exitt.xpm", &(mlx_pointers->exit));
	mlx_loop(mlx_pointers->mlx_p);
}
