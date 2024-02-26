/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:27:06 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/26 18:04:28 by ichaabi          ###   ########.fr       */
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
void	fill(char **new_map, int i, int j)
{
	if (i < 0 || i >= map_count(new_map[0]) ||\
	j < 0 || j >= ft_strlen(new_map[0]) ||\
	new_map[i][j] == '1' || new_map[i][j] == 'I' || new_map[i][j] =='E')
		return ;
	new_map[i][j] = 'I';
	fill(new_map, i - 1, j);
	fill(new_map, i + 1, j);
	fill(new_map, i, j - 1);
	fill(new_map, i, j + 1);
}

int	checking_valid_path(char **two_d)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	j = 0;
	new_map = copy_map(two_d);
	while (new_map[i] != NULL)
	{
		j = 0;
		while (new_map[i][j] != '\0')//ila c || e mahdahom hta I donc maandhomsh acces
		{
			if ((new_map[i][j] == 'C') || (new_map[i][j] == 'E' &&\
				new_map[i][j] != 'I' && new_map[i + 1][j] != 'I' &&\
				new_map[i - 1][j] && new_map[i][j - 1] != 'I' && new_map[i][j + 1] != 'I'))
					ft_putstr_fd("Error\n", 2);
			j++;
		}
		i++;
	}
}

void	the_valid_path(char **two_d, t_position *r)
{
	char	**new_map;

	new_map = copy_map(two_d);
	fill(new_map, r->i, r->j);
	checking_valid_path(new_map);
}
