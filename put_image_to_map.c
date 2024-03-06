/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:06:28 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/05 20:32:11 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(char **map, t_mlx mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
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
			j++;
		}
		i++;
	}
}
