/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directionss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:42:28 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/03 03:00:58 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_up(t_mlx *mlx)
{

	if (mlx->map[mlx->i - 1][mlx->j] == '0')
	{
		mlx->map[mlx->i - 1][mlx->j] = 'P';
		mlx->map[mlx->i + 1][mlx->j] = '0';
		count_moves(mlx);
	}
	else if (mlx->map[mlx->i - 1][mlx-> j] == 'C')
	{
		mlx->map[mlx->i - 1][mlx-> j] = 'P';
		mlx->map[mlx->i + 1][mlx->j] = '0';
		count_moves(mlx);
	}
	else if (mlx->map[mlx->i -1][mlx-> j] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			count_moves(mlx);
			ft_putstr_fd("WINNER !!", 1);
			close_map(mlx);
		}
		else
			game_over();
	}
}

void	to_down(t_mlx *mlx)
{
	if (mlx->map[mlx->i + 1][mlx->j + 1] == '0')
	{
		mlx->map[mlx->i + 1][mlx->j] = 'P';
		mlx->map[mlx->i - 1][mlx->j] = '0';
		count_moves(mlx);
	}
	else if (mlx->map[mlx->i + 1][mlx->j] == 'C')
	{
		mlx->map[mlx->i + 1][mlx-> j] = 'P';
		mlx->map[mlx->i - 1][mlx->j] = '0';
		count_moves(mlx);
	}
	else if (mlx->map[mlx->i + 1][mlx-> j] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			count_moves(mlx);
			ft_putstr_fd("WINNER !!", 1);
			close_map(mlx);
		}
		else
			game_over();
	}
}
void	to_right(t_mlx *mlx)
{
	if (mlx->map[mlx->i][mlx->j + 1] == '0')
	{
		mlx->map[mlx->i][mlx->j + 1] = 'P';
		mlx->map[mlx->i][mlx->j - 1] = '0';
		count_moves(mlx);
	}
	else if (mlx->map[mlx->i][mlx-> j + 1] == 'C')
	{
		mlx->map[mlx->i][mlx-> j + 1] = 'P';
		mlx->map[mlx->i][mlx->j - 1] = '0';
		count_moves(mlx);
	}
	else if (mlx->map[mlx->i][mlx-> j + 1] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			count_moves(mlx);
			ft_putstr_fd("WINNER !!", 1);
			close_map(mlx);
		}
		else
			game_over();
	}
}
void	to_left(t_mlx *mlx)
{
	if (mlx->map[mlx->i][mlx->j - 1] == '0')
	{
		mlx->map[mlx->i][mlx->j - 1] = 'P';
		mlx->map[mlx->i][mlx->j + 1] = '0';
		count_moves(mlx);
	}
	else if (mlx->map[mlx->i][mlx-> j - 1] == 'C')
	{
		mlx->map[mlx->i][mlx-> j - 1] = 'P';
		mlx->map[mlx->i][mlx->j + 1] = '0';
		count_moves(mlx);
	}
	else if (mlx->map[mlx->i][mlx-> j - 1] == 'E')
	{
		if (how_many(mlx->map) == 0)
		{
			count_moves(mlx);
			ft_putstr_fd("WINNER !!", 1);
			close_map(mlx);
		}
		else
			game_over();
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

void	count_moves(t_mlx *mlx)
{
	static	int moves;

	moves += 1;
	printf("%d\n", moves);
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

void	game_over()
{
	errors("GAME OVER !\n", 2);
}

void	destory_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_p, mlx->wall);
	mlx_destroy_image(mlx->mlx_p, mlx->background);
	mlx_destroy_image(mlx->mlx_p, mlx->player);
	mlx_destroy_image(mlx->mlx_p, mlx->collect);
	mlx_destroy_image(mlx->mlx_p, mlx->exit);
}

void	hook(t_mlx *mlx, int keycode)
{
	if (keycode == 53)
		close_map(mlx);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		destory_img(mlx);//avant le deplacement du joueur pour la mise a jour
		move_u_d_l_r(mlx, keycode);
		initialize(mlx);
		the_mlx(mlx);
		print_img(mlx->map, *mlx);
	}
}