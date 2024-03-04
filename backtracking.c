/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:27:06 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/05 00:12:24 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_P_C_E(char **two_d)
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
					errors("Error\nwalls autour de P || C || E\n", 2);
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
	if (i < 0 || i >= map_count(new_map) ||\
	j < 0 || j >= ft_strlen(new_map[0]) ||\
	new_map[i][j] == '1' || new_map[i][j] == 'I' || new_map[i][j] =='E')
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
		while (j < ft_strlen(new_map[i]))//ila c || e mahdahom hta I donc maandhomsh acces
		{
			if (new_map[i][j] == 'C' || (new_map[i][j] == 'E' && new_map[i - 1][j] != 'I' && new_map[i + 1][j] != 'I' &&
				 new_map[i][j - 1] != 'I' && new_map[i][j + 1] != 'I'))
			{
					errors("Error\nC||E mahdahom hta i donc maandhomsh acces\n", 2);
			}
			j++;
		}
		i++;
	}
}


void print_map(char **two_d)
{
	int i;

	i = 0;
	while (two_d[i])
	{
		printf("copy_map[%d] == %s\n", i , two_d[i]);
		i++;
	}
}

void	the_valid_path(char **two_d, t_position *r)
{

	(void)r;
	char	**new_map;
	int i;
	int j;

	i = 0;
	j = 0;
	new_map = copy_map(two_d);
	// print_map(new_map);
	find_player(new_map, &i, &j);
	// printf("before === fill\n");
	recursive_fill(new_map, i, j);
	// printf("after === fill\n");
	// print_map(new_map);
	checking_valid_path(new_map);

}
