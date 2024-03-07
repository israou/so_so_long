/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:57:52 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/07 23:59:16 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_img(char **map, t_mlx mlx)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				put_image(&mlx, i, j, mlx.player);
			else if (map[i][j] == 'C')
				put_image(&mlx, i, j, mlx.collect);
			else if (map[i][j] == '1')
				put_image(&mlx, i, j, mlx.wall);
			else if (map[i][j] == 'E')
				put_image(&mlx, i, j, mlx.exit);
			else if (map[i][j] == '0')
				put_image(&mlx, i, j, mlx.background);
			else if (map[i][j] == 'D')
				put_image(&mlx, i, j, mlx.enemy);
			j++;
		}
	}
}
