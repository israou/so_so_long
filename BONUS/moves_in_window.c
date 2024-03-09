/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_in_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:27:40 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/09 01:11:01 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return ((ft_strdup("0")));
	i = len(n);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (n > 0)
	{
		str[i - 1] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}
void	put_moves(t_mlx *mlx_pointers, int moves)
{
	char	*move_s;

	move_s = ft_itoa(moves);
	if (!move_s)
		errors("Error\nConverting moves to string\n", 2);
	mlx_string_put(mlx_pointers->mlx_p, mlx_pointers->win_p, 20, 20, 0xFFFFFF, "Moves : ");
	mlx_string_put(mlx_pointers->mlx_p, mlx_pointers->win_p, 100, 20, 0xFFFFFF, move_s);
}