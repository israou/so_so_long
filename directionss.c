/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directionss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:42:28 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/06 01:42:58 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_up(t_mlx *mlx)
{
	find_player(mlx->map, &(mlx->i), &(mlx->j));
	if (mlx->map[mlx->i - 1][mlx->j] == '0')
	{
		mlx->moves++;
		// g_moves++;
		mlx->map[mlx->i - 1][mlx->j] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (mlx->map[mlx->i - 1][mlx-> j] == 'C')
	{
		// g_moves++;
		mlx->moves++;
		mlx->map[mlx->i - 1][mlx->j] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (mlx->map[mlx->i -1][mlx-> j] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			ft_putstr_fd("WINNER !!", 1);
			close_map(mlx);
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
		mlx->moves++;
		// g_moves++;
		ft_putnbr_fd(g_moves, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (mlx->map[mlx-> i + 1][mlx-> j] == 'C')
	{
		mlx->map[mlx->i + 1][mlx->j] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		// g_moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (mlx->map[mlx-> i + 1][mlx-> j] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			ft_putstr_fd("WINNER !!", 1);
			close_map(mlx);
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
		// g_moves++;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (mlx->map[mlx->i][mlx-> j + 1] == 'C')
	{
		mlx->map[mlx->i][mlx->j + 1] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		// g_moves++;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (mlx->map[mlx->i][mlx-> j + 1] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			ft_putstr_fd("WINNER !!", 1);
			close_map(mlx);
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
		// g_moves++;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (mlx->map[mlx->i][mlx-> j - 1] == 'C')
	{
		mlx->map[mlx->i][mlx->j - 1] = 'P';
		mlx->map[mlx->i][mlx->j] = '0';
		// g_moves++;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd("\n", 1);
	}
	else if (mlx->map[mlx->i][mlx-> j - 1] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			ft_putstr_fd("WINNER !!", 1);
			close_map(mlx);
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
