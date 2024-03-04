/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directionss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:42:28 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/04 23:05:17 by ichaabi          ###   ########.fr       */
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
void	to_up(t_mlx *mlx)
{
	static int	moves;

	moves = 0;
	find_player(mlx->map, mlx->i, mlx->j);
	while (mlx->map[mlx->i][mlx->j] == 'P')
	{
		if (mlx->map[mlx->i - 1][mlx->j] == '0')
		{
			put_image(mlx, mlx->i - 1, mlx->j - 1, mlx->player);
			put_image(mlx, mlx->i + 1, mlx->j, mlx->background);
			moves++;
		}
		else if (mlx->map[mlx->i - 1][mlx-> j] == 'C')
		{
			put_image(mlx, mlx->i - 1, mlx->j, mlx->player);
			put_image(mlx, mlx->i + 1, mlx->j, mlx->background);
			moves++;
		}
		else if (mlx->map[mlx->i -1][mlx-> j] == 'E')
		{
			if (how_many(mlx->map) == 0)
			{
				put_image(mlx, mlx->i - 1, mlx->j, mlx->player);
				put_image(mlx, mlx->i + 1, mlx->j, mlx->background);
				moves++;
				ft_putstr_fd("WINNER !!", 1);
				close_map(mlx);
			}
			else
				game_over(mlx);
		}
	}
}


void	to_down(t_mlx *mlx)
{
	static int	moves;

	moves = 0;
	find_player(mlx->map, mlx->i, mlx->j);
	while (mlx->map[mlx->i][mlx->j] == 'P')
	{
		if (mlx->map[mlx-> i + 1][mlx-> j] == '0')
		{
			put_image(mlx, mlx->i + 1, mlx->j - 1, mlx->player);
			put_image(mlx, mlx->i - 1, mlx->j, mlx->background);
			moves++;
		}
		else if (mlx->map[mlx-> i + 1][mlx-> j] == 'C')
		{
			put_image(mlx, mlx->i + 1, mlx->j, mlx->player);
			put_image(mlx, mlx->i - 1, mlx->j, mlx->background);
			moves++;
		}
		else if (mlx->map[mlx-> i + 1][mlx-> j] == 'E')
		{
			if (how_many(mlx->map) == 0)
			{
				put_image(mlx, mlx->i + 1, mlx->j, mlx->player);
				put_image(mlx, mlx->i - 1, mlx->j, mlx->background);
				moves++;
				ft_putstr_fd("WINNER !!", 1);
				close_map(mlx);
			}
			else
				game_over(mlx);
		}
	}
}
void	to_right(t_mlx *mlx)
{
	static int	moves;

	moves = 0;
	find_player(mlx->map, mlx->i, mlx->j);
	while (mlx->map[mlx->i][mlx->j] == 'P')
	{
		if (mlx->map[mlx->i][mlx->j + 1] == '0')
		{
			put_image(mlx, mlx->i, mlx->j + 1, mlx->player);
			put_image(mlx, mlx->i, mlx->j - 1, mlx->background);
			moves++;
			ft_putstr_fd(moves, 1);//khasni nprinti lmoves
		}
		else if (mlx->map[mlx->i][mlx-> j + 1] == 'C')
		{
			put_image(mlx, mlx->i, mlx->j + 1, mlx->player);
			put_image(mlx, mlx->i, mlx->j - 1, mlx->background);
			moves++;
		}
		else if (mlx->map[mlx->i][mlx-> j + 1] == 'E')
		{
			if (how_many(mlx->map) == 0)
			{
				put_image(mlx, mlx->i, mlx->j + 1, mlx->player);
				put_image(mlx, mlx->i, mlx->j - 1, mlx->background);
				moves++;
				ft_putstr_fd("WINNER !!", 1);
				close_map(mlx);
			}
			else
				game_over(mlx);
		}
	}
}
void	to_left(t_mlx *mlx)
{
	static int	moves;

	moves = 0;
	find_player(mlx->map, mlx->i, mlx->j);
	while (mlx->map[mlx->i][mlx->j] == 'P')
	{
		if (mlx->map[mlx->i][mlx->j - 1] == '0')
		{
			put_image(mlx, mlx->i, mlx->j - 1, mlx->player);
			put_image(mlx, mlx->i, mlx->j + 1, mlx->background);
			moves++;
		}
		else if (mlx->map[mlx->i][mlx-> j - 1] == 'C')
		{
			put_image(mlx, mlx->i, mlx->j - 1, mlx->player);
			put_image(mlx, mlx->i, mlx->j + 1, mlx->background);
			moves++;
		}
		else if (mlx->map[mlx->i][mlx-> j - 1] == 'E')
		{
			if (how_many(mlx->map) == 0)
			{
				put_image(mlx, mlx->i, mlx->j - 1, mlx->player);
				put_image(mlx, mlx->i, mlx->j + 1, mlx->background);
				moves++;
				ft_putstr_fd("WINNER !!", 1);
				close_map(mlx);
			}
			else
				game_over(mlx);
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

int	hook(t_mlx *mlx, int keycode)
{
	if (keycode == 53)
		close_map(mlx);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		destory_img(mlx);// Destruction des anciennes images avant le déplacement du joueur pour la mise à jour
		move_u_d_l_r(mlx, keycode);//deplacement du joueur en fonction de la touche pressée
		initialize(mlx);//reintialisation de l interface graphique
		the_mlx(mlx);//mise a jour des images
		print_img(mlx->map, *mlx);//affichage du jeu
	}
	return (0);
}
