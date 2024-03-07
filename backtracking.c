/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:27:06 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/06 18:23:34 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **two_d)
{
	int		i;
	char	**copie_map;

	i = map_count(two_d);
	copie_map = (char **) malloc (sizeof(char *) * i);
	if (!copie_map)
		return (NULL);
	i = 0;
	while (two_d[i])
	{
		copie_map[i] = ft_strdup(two_d[i]);
		if (!copie_map[i])
			errors("Error\nstrdup for coie_map failed\n", 2);
		i++;
	}
	copie_map[i] = NULL;
	return (copie_map);
}

void	recursive_fill(char **new_map, int i, int j)
{
	if (i < 0 || i >= map_count(new_map) || \
	j < 0 || j >= ft_strlen(new_map[0]) || \
	new_map[i][j] == '1' || new_map[i][j] == 'I' || new_map[i][j] == 'E')
		return ;
	new_map[i][j] = 'I';
	recursive_fill(new_map, i - 1, j);
	recursive_fill(new_map, i + 1, j);
	recursive_fill(new_map, i, j - 1);
	recursive_fill(new_map, i, j + 1);
}

void	checking_valid_path(char **new_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map_count(new_map))
	{
		j = 0;
		while (j < ft_strlen(new_map[i]))
		{
			if (new_map[i][j] == 'C' || (new_map[i][j] == 'E' \
			&& new_map[i - 1][j] != 'I' && new_map[i + 1][j] != 'I' && \
			new_map[i][j - 1] != 'I' && new_map[i][j + 1] != 'I'))
			{
				errors("Error\ncant access characters \n", 2);
			}
			j++;
		}
		i++;
	}
}

void	the_valid_path(char **two_d)
{
	char	**new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_map = copy_map(two_d);
	find_player(new_map, &i, &j);
	recursive_fill(new_map, i, j);
	checking_valid_path(new_map);
	ft_free(new_map);
}

char	**ft_free(char **two_d)
{
	int	i;

	i = 0;
	while (two_d[i])
	{
		free(two_d[i]);
		i++;
	}
	free(two_d);
	return (NULL);
}
