/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:48:39 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/02 03:01:59 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_mlx *mlx)
{
	mlx->height = map_count(mlx->map) * 64;
	mlx->width = ft_strlen(mlx->map[0]) * 64;
	the_mlx(mlx);
}
