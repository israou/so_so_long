/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:52:55 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/03 02:42:37 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// void	clear_window(t_mlx *mlx)
// {
// 	mlx_clear_window(mlx->mlx_p, mlx->win_p);
// }


// void	game_over()
// {
// 	errors("GAME OVER !\n", 2);
// }

// void	move_up(t_mlx *mlx, int *i, int *j)
// {
// 	if (mlx->map[*i - 1][*j] == '0')
// 	{
// 		mlx->map[*i - 1][*j] == 'P';
// 		mlx->map[*i + 1][*j] == '0';
// 		count_moves(mlx);
// 	}
// 	else if (mlx->map[*i - 1][*j] == 'C')
// 	{
// 		mlx->map[*i - 1][*j] == 'P';
// 		mlx->map[*i + 1][*j] == '0';
// 		count_moves(mlx);
// 	}
// 	else if (mlx->map[*i - 1][*j] == 'E')
// 	{
// 		if (how_many(mlx->map) == 0)
// 		{
// 			count_moves(mlx);
// 			ft_putstr_fd("WINNER !!", 1);
// 			close_map(mlx);
// 		}
// 		else
// 			game_over();
// 	}

// }
// void	to_up(t_mlx *mlx)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (mlx->map[i])
// 		j = 0;
// 		while (mlx->map[i][j])
// 		{
// 			if (mlx->map[i][j] == 'P')
// 			{
// 				move_up(mlx, &i, &j);
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// }

// int how_many(char **two_d)
// {
// 	int	i;
// 	int	j;
// 	int	c_found;

// 	i = 0;
// 	j = 0;
// 	c_found = 0;
// 	while (two_d[i])
// 	{
// 		j = 0;
// 		while (two_d[i][j])
// 		{
// 			if (two_d[i][j] == 'C')
// 				c_found++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (c_found);
// }

// void	count_moves(t_mlx *mlx)
// {
// 	static	int moves;

// 	moves += 1;
// 	printf("%d\n", moves);
// }
// //ndir next fiha clear fill w thseb lmoves donc andi 3 fonctions
