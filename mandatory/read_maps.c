/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:49:50 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/07 23:12:33 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_maps(int fd, char *av)
{
	int		i;
	char	**lines;
	char	*line;

	i = max_line(fd);
	close(fd);
	fd = open(av, O_RDONLY);
	lines = (char **)malloc(sizeof(char *) * (i + 1));
	if (!lines)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines[i] = ft_strdup(line);
		free(line);
		if (!lines[i])
			break ;
		i++;
	}
	lines[i] = NULL;
	return (lines);
}

int	max_line(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	return (i);
}

int	valid_p_c_e(char **two_d)
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
				&& two_d[i][j - 1] == '1' && two_d[i][j + 1] == '1')
					errors("Error\nwalls autour de P || C || E\n", 2);
			}
			j++;
		}
		i++;
	}
	return (0);
}
