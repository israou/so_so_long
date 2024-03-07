/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:56:40 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/07 23:56:47 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize(t_mlx *mlx)
{
	mlx->height = map_count(mlx->map) * 80;
	mlx->width = ft_strlen(mlx->map[0]) * 80;
	the_mlx(mlx);
}
