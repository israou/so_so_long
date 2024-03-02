/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:48:39 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/02 00:15:47 by ichaabi          ###   ########.fr       */
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
}
	// w = 64;
	// h = 64;
	// the_mlx();
	// map->height = map_count(map->map) * 64;
	// map->width = ft_strlen(map->map[0]) * 64;