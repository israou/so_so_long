/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directionss_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:05:01 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/09 00:50:49 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	to_up(t_mlx *mlx)
{
	find_player(mlx->map, &(mlx->i), &(mlx->j));
	if (mlx->map[mlx->i - 1][mlx->j] == '0')
	{
		mlx->map[mlx->i - 1][mlx->j] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		put_moves(mlx, ++(mlx->moves));
	}
	else if (mlx->map[mlx->i - 1][mlx-> j] == 'C')
	{
		mlx->map[mlx->i - 1][mlx->j] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		put_moves(mlx, ++(mlx->moves));
	}
	else if (mlx->map[mlx->i -1][mlx-> j] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			ft_putstr_fd("WINNER !!", 1);
			close_map();
		}
	}
}

void	to_down(t_mlx *mlx)
{
	find_player(mlx->map, &(mlx->i), &(mlx->j));
	if (mlx->map[mlx-> i + 1][mlx-> j] == '0')
	{
		mlx->map[mlx->i + 1][mlx->j] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		put_moves(mlx, ++(mlx->moves));
	}
	else if (mlx->map[mlx-> i + 1][mlx-> j] == 'C')
	{
		mlx->map[mlx->i + 1][mlx->j] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		put_moves(mlx, ++(mlx->moves));
	}
	else if (mlx->map[mlx-> i + 1][mlx-> j] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			ft_putstr_fd("WINNER !!", 1);
			close_map();
		}
	}
}

void	to_right(t_mlx *mlx)
{
	find_player(mlx->map, &(mlx->i), &(mlx->j));
	if (mlx->map[mlx->i][mlx->j + 1] == '0')
	{
		mlx->map[mlx->i][mlx->j + 1] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		put_moves(mlx, ++(mlx->moves));
	}
	else if (mlx->map[mlx->i][mlx-> j + 1] == 'C')
	{
		mlx->map[mlx->i][mlx->j + 1] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		put_moves(mlx, ++(mlx->moves));
	}
	else if (mlx->map[mlx->i][mlx-> j + 1] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			ft_putstr_fd("WINNER !!", 1);
			close_map();
		}
	}
}

void	to_left(t_mlx *mlx)
{
	find_player(mlx->map, &(mlx->i), &(mlx->j));
	if (mlx->map[mlx->i][mlx->j - 1] == '0')
	{
		mlx->map[mlx->i][mlx->j - 1] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		put_moves(mlx, ++(mlx->moves));
	}
	else if (mlx->map[mlx->i][mlx-> j - 1] == 'C')
	{
		mlx->map[mlx->i][mlx->j - 1] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		put_moves(mlx, ++(mlx->moves));
	}
	else if (mlx->map[mlx->i][mlx-> j - 1] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			ft_putstr_fd("WINNER !!", 1);
			close_map();
		}
	}
}

void	move_u_d_l_r(t_mlx *mlx, int keycode)
{
	if (keycode == W)
		to_up(mlx);
	else if (keycode == A)
		to_left(mlx);
	else if (keycode == S)
		to_down(mlx);
	else if (keycode == D)
		to_right(mlx);
}
