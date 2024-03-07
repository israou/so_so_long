/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:24:23 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/07 23:41:47 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] == 'r' && str[--i] == 'e' && str[--i] == 'b' && str[--i] == '.' && str[--i] != '\0')
		return ;
	errors("Error\nExtension error\n", 2);
}

int	check_empty(char **two_d)
{
	int	i;
	int	j;

	i = 0;
	while (two_d[i] != NULL)
	{
		j = 0;
		while (two_d[i][j] != '\0')
		{
			if ((two_d[i][j] >= 9 && two_d[i][j] <= 13) || (two_d[i][j] == ' '))
				errors("Error\nSpaces error\n", 2);
			j++;
		}
		i++;
		if (j == 0)
			errors("Error\nEmpty line error\n", 2);
	}
	return (0);
}

void	check_maps2(int efound, int cfound, int pfound)
{
	if (efound != 1 || cfound == 0 || pfound != 1)
		errors("Error\nInvalid number of P||C||E\n", 2);
}

void	check_maps(char **two_d)
{
	int	i;
	int	j;
	int	efound;
	int	cfound;
	int	pfound;

	efound = 0;
	cfound = 0;
	pfound = 0;
	i = -1;
	while (two_d[++i])
	{
		j = 0;
		while (two_d[i][j])
		{
			if (two_d[i][j] == 'E')
				efound++;
			else if (two_d[i][j] == 'P')
				pfound++;
			else if (two_d[i][j] == 'C')
				cfound++;
			j++;
		}
	}
	check_maps2(efound, cfound, pfound);
}
void	check_enemy2(int dfound)
{
	if (dfound != 1)
		errors("Error\nInvalid number of enemy", 2);
}

void	check_enemy(char **two_d)
{
	int	i;
	int	j;
	int	dfound;

	i = 0;
	j = 0;
	dfound = 0;
	while (two_d[i])
	{
		j = 0;
		while (two_d[i][j])
		{
			if (two_d[i][j] == 'D')
				dfound++;
			j++;
		}
		i++;
	}
	check_enemy2(dfound);
}
void	check_valid_char(char **two_d)
{
	int		i;
	int		j;
	char	thischar;

	i = 0;
	while (two_d[i] != NULL)
	{
		j = 0;
		while (two_d[i][j] != '\0')
		{
			thischar = two_d[i][j];
			if (!(thischar == '0' || thischar == '1' || thischar == 'E' || \
			thischar == 'C' || thischar == 'P' || thischar == 'D'))
				errors("Error\nInvalid character\n", 2);
			j++;
		}
		i++;
	}
}
