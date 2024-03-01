/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:48:39 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/01 00:49:48 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_mlx *map)
{
	int	w;
	int	h;


	w = 64;
	h = 64;
	map->height = map_count(map->map) * 64;
	map->width = ft_strlen(map->map[0]) * 64;
	the_mlx();
	// map->mlx_p = mlx_init();
	// if (!mlx_init)
	// 	errors("Error init\n", 2);

	// map->win_p = mlx_new_window(map->mlx_p, 1920, 1080, "robio");
}