/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:11:26 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/06 19:42:13 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(char **two_d, int *i, int *j)
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

int	how_many(char **two_d)
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

int	close_map(void)
{
	ft_putstr_fd(" \t\t\t OUTTT !\n", 2);
	exit(0);
	return (0);
}
