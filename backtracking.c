/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:27:06 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/26 16:00:06 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_player(char **two_d)
{
	int	i;
	int	j;

	i = 0;
	while (two_d[i])
	{
		j = 0;
		while (two_d[i][j])
		{
			if (two_d[i][j] == 'P' || two_d[i][j] == 'C' || two_d[i][j] == 'E')
			{
				if (two_d[i - 1][j] == '1' && two_d[i + 1][j] == '1'
					&& two_d[i][j - 1] == '1' && two_d[i][ j + 1] == '1')
					ft_putstr_fd("Error\n", 2);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**copy_map(char **two_d)
{
	int	i;
	char	**copie_map;

	i = map_count(two_d);
	copie_map = (char **) malloc (sizeof(char *) * i);
	if (!copie_map)
		ft_putstr_fd("Error\n", 2);
	i = 0;
	while (two_d[i])
	{
		copie_map[i] = ft_strdup(two_d[i]);
		if (!copie_map[i])
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	copie_map[i] = NULL;
	return (copie_map);
}
int	valid_path(char **two_d)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	j = 0;
	new_map = copy_map(two_d);
	while (new_map[i])
	{
		j = 0;
		while (two_d[i][j])
		{
			if (new_map[i][j] == 'P')
			{
				if (new_map[i - 1][j] == '0')
				
				{
					new_map[i][j] = 'I';
					new_map[i - 1][j] = 'P';
				}
				if (new_map[i + 1][j] == '0')
				{
					new_map[i][j] = 'I';
					new_map[i + 1][j] = 'P';
				}
				if (new_map[i][j - 1] == '0')
				{
					new_map[i][j] = 'I';
					new_map[i][j - 1] = 'P';
				}
				if (new_map[i][j + 1] == '0')
				{
					new_map[i][j] = 'I';
					new_map[i][j + 1] = 'P';
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (two_d[i])
	{
		printf(">> %s\n", two_d[i]);
		i++;
	}
	return (0);
}
