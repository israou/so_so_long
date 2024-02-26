/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:19:09 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/26 15:33:20 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls_top_down(char **two_d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (two_d[i][j])
	{
		if (two_d[i][j] != '1')
			ft_putstr_fd("Error\n", 2);
		j++;
	}
	i = map_count(two_d) - 1;//hit l indice ki bda men 0
	j = 0;
	while (two_d[i][j])
	{
		if (two_d[i][j] != '1')
			ft_putstr_fd("Error\n", 2);
		j++;
	}
}

void	check_walls_left_right(char **two_d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	//str finit par \0,, 2D array par null
	while (two_d[i] != NULL)//hit ayhbet htal lekher
	{
		if (two_d[i][j] != '1')
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	i = 0;
	j = 0;
	while (two_d[i] != NULL)
	{
		j = ft_strlen(two_d[i]);
		if (two_d[i][j - 1] != '1')
			ft_putstr_fd("Error\n", 2);
		i++;
	}
}

int	map_count(char **two_d)
{
	int	i;

	i = 0;
	while (two_d[i] != NULL)
		i++;
	return (i);
}

void	check_long_of_map(char **two_d)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	j = 0;
	size = ft_strlen(two_d[0]);
	while (two_d[i] != NULL)
	{
		if (size != ft_strlen(two_d[i]))
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	// if (i >= size)
	// 	ft_putstr_fd("Error\n", 2);
}