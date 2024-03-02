/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:06:28 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/02 02:21:50 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(char **map, t_mlx mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_put_image_to_window(mlx.mlx_p, mlx.win_p, mlx.background, 0, 0);
	while (map[i])
	{
		while (map[i][j])
		{
			j = 0;
			if (map[i][j] == 'P')
				put_image(&mlx, i, j, mlx.player);
			else if (map[i][j] == 'C')
				put_image(&mlx, i, j, mlx.collect);
			else if (map[i][j] == '1')
				put_image(&mlx, i, j, mlx.wall);
			else if (map[i][j] == 'E')
				put_image(&mlx, i, j, mlx.exit);
			j++;
		}
		i++;
	}
}
