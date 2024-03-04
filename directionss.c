/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directionss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:42:28 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/04 23:22:45 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_putstr_fd(ft_itoa(moves), 1);
		}
		else if (mlx->map[mlx->i - 1][mlx-> j] == 'C')
		{
			put_image(mlx, mlx->i - 1, mlx->j, mlx->player);
			put_image(mlx, mlx->i + 1, mlx->j, mlx->background);
			moves++;
			ft_putstr_fd(ft_itoa(moves), 1);
		}
		else if (mlx->map[mlx->i -1][mlx-> j] == 'E')
		{
			if (how_many(mlx->map) == 0)
			{
				put_image(mlx, mlx->i - 1, mlx->j, mlx->player);
				put_image(mlx, mlx->i + 1, mlx->j, mlx->background);
				moves++;
				ft_putstr_fd(ft_itoa(moves), 1);
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
			ft_putstr_fd(ft_itoa(moves), 1);
		}
		else if (mlx->map[mlx-> i + 1][mlx-> j] == 'C')
		{
			put_image(mlx, mlx->i + 1, mlx->j, mlx->player);
			put_image(mlx, mlx->i - 1, mlx->j, mlx->background);
			moves++;
			ft_putstr_fd(ft_itoa(moves), 1);
		}
		else if (mlx->map[mlx-> i + 1][mlx-> j] == 'E')
		{
			if (how_many(mlx->map) == 0)
			{
				put_image(mlx, mlx->i + 1, mlx->j, mlx->player);
				put_image(mlx, mlx->i - 1, mlx->j, mlx->background);
				moves++;
				ft_putstr_fd(ft_itoa(moves), 1);
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
			ft_putstr_fd(ft_itoa(moves), 1);
			ft_putstr_fd(moves, 1);//khasni nprinti lmoves
		}
		else if (mlx->map[mlx->i][mlx-> j + 1] == 'C')
		{
			put_image(mlx, mlx->i, mlx->j + 1, mlx->player);
			put_image(mlx, mlx->i, mlx->j - 1, mlx->background);
			moves++;
			ft_putstr_fd(ft_itoa(moves), 1);
		}
		else if (mlx->map[mlx->i][mlx-> j + 1] == 'E')
		{
			if (how_many(mlx->map) == 0)
			{
				put_image(mlx, mlx->i, mlx->j + 1, mlx->player);
				put_image(mlx, mlx->i, mlx->j - 1, mlx->background);
				moves++;
				ft_putstr_fd(ft_itoa(moves), 1);
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
			ft_putstr_fd(ft_itoa(moves), 1);
		}
		else if (mlx->map[mlx->i][mlx-> j - 1] == 'C')
		{
			put_image(mlx, mlx->i, mlx->j - 1, mlx->player);
			put_image(mlx, mlx->i, mlx->j + 1, mlx->background);
			moves++;
			ft_putstr_fd(ft_itoa(moves), 1);
		}
		else if (mlx->map[mlx->i][mlx-> j - 1] == 'E')
		{
			if (how_many(mlx->map) == 0)
			{
				put_image(mlx, mlx->i, mlx->j - 1, mlx->player);
				put_image(mlx, mlx->i, mlx->j + 1, mlx->background);
				moves++;
				ft_putstr_fd(ft_itoa(moves), 1);
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
