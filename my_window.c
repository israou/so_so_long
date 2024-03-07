/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:21:01 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/07 23:08:22 by ichaabi          ###   ########.fr       */
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
	mlx_pointers->win_p = mlx_new_window(mlx_pointers->mlx_p, \
	ft_strlen(mlx_pointers->map[0]) * 80, map_count(mlx_pointers->map) * 80, \
	"SO_LONG");
	if (!mlx_pointers->win_p)
		errors("Error 4 window\n", 2);
}

void	load_and_display_image(t_mlx *mlx_pointers, char *filename, void **p)
{
	*p = mlx_xpm_file_to_image(mlx_pointers->mlx_p, filename, \
	&(mlx_pointers->width), &(mlx_pointers->height));
	if (!*p)
		errors("Error loading XPM image\n", 2);
}

void	put_image(t_mlx *mlx, int i, int j, void *img)
{
	mlx_put_image_to_window(mlx->mlx_p, mlx->win_p, img, j * 80, i * 80);
}

void	the_mlx(t_mlx *mlx_pointers)
{
	mlx_pointers->width = 0;
	mlx_pointers->height = 0;
	init_mlx(mlx_pointers);
	create_window(mlx_pointers);
	load_and_display_image(mlx_pointers, "sky.xpm", \
	&(mlx_pointers->background));
	load_and_display_image(mlx_pointers, "mybrain.xpm", \
	&(mlx_pointers->collect));
	load_and_display_image(mlx_pointers, "me.xpm", &(mlx_pointers->wall));
	load_and_display_image(mlx_pointers, "alien.xpm", &(mlx_pointers->player));
	load_and_display_image(mlx_pointers, "thexit.xpm", &(mlx_pointers->exit));
}
