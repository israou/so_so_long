/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:49:50 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/24 01:58:22 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_maps(int fd, char *av)
{
	int		i;
	char	**lines;
	char	*line;

	i = max_line(fd);
	close(fd);
	fd = open(av, O_RDONLY);
	lines = (char **)malloc(sizeof(char *) * i);//le nbre max de ligne a representer dans le tableau a 2d
	if (!lines)
		return(NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;//si la lecture echoue,,ou j atteigne la fin du fichier
		lines[i] = ft_strdup(line);//nstocker la ligne li tqrat ftableau 2d
		free(line);//nfreyer l getnextline
		if (!lines[i])
			break;
		i++;// bash idouz fl array dialna next block
	}
	lines[i] = NULL;
	return (lines);
}
//ma fonction appelle get_next_line pour lire dans fd, elle stocke chaque ligne dans le tableau
//en utilisant strdup pour creer une copie de la ligne lue
//flekher elle retourne lines
//backtracking algorithm for checking a valid path
int	max_line(int fd)
{
	int i;
	char *line;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		free(line);
		i++;
	}
	return (i);
}