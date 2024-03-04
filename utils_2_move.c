/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:11:26 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/04 23:13:18 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player(char **two_d, int *i, int *j)
{
	while (two_d[*i])
	{
		*j = 0;
		while (two_d[*i][*j])
		{
			if (two_d[*i][*j] == 'P')
				return ;
			(*j)++;
		}
		(*i)++;
	}
}

int how_many(char **two_d)
{
	int	i;
	int	j;
	int	c_found;

	i = 0;
	j = 0;
	c_found = 0;
	while (two_d[i])
	{
		j = 0;
		while (two_d[i][j])
		{
			if (two_d[i][j] == 'C')
				c_found++;
			j++;
		}
		i++;
	}
	return (c_found);
}

void	close_map(t_mlx *mlx)
{
	ft_putstr_fd(" \t\t\t OUTTT !\n", 2);
	mlx_destroy_window(mlx->mlx_p, mlx->win_p);
	exit(0);
}

void	game_over(t_mlx *mlx)
{
	mlx->map = mlx;
	errors("GAME OVER !\n", 2);
	close_map(mlx);
}

void	destory_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_p, mlx->wall);
	mlx_destroy_image(mlx->mlx_p, mlx->background);
	mlx_destroy_image(mlx->mlx_p, mlx->player);
	mlx_destroy_image(mlx->mlx_p, mlx->collect);
	mlx_destroy_image(mlx->mlx_p, mlx->exit);
}