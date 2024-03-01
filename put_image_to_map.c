/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:06:28 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/01 00:41:04 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx	*mlx_p, int i, int j, char *img)
{
	void	*w;
	void	*themap;
	w = mlx_p->win_p;
	themap = mlx_p->map;
	mlx_put_image_to_window(themap, w, img, i, j);
}
void	print_img(char **map, t_mlx mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			j = 0;
			if (map[i][j] == 'P')
				put_image(&mlx, i, j, "p1.xpm");
			else if (map[i][j] == 'C')
				put_image(&mlx, i, j, "collectibles.xpm");
			else if (map[i][j] == '1')
				put_image(&mlx, i, j, "walll.xpm");
			else if (map[i][j] == 'E')
				put_image(&mlx, i, j, "exitt.xpm");
			else if (map[i][j] == '0')
				;
			j++;
		}
		i++;
	}
}
