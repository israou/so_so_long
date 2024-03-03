/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:48:39 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/02 23:25:32 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_mlx *mlx)
{
	mlx->height = map_count(mlx->map) * 80;
	mlx->width = ft_strlen(mlx->map[0]) * 80;
	the_mlx(mlx);
}
