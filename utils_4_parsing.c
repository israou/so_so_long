/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:03:40 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/24 18:13:26 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	i--;
	if (str[i] == 'r' && str[--i] == 'e' && str[--i] == 'b' && str[--i] == '.')
		return ;
	ft_putstr_fd("Error\n", 2);
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
				ft_putstr_fd("Error\n", 2);
			j++;//caractere suivant
		}
		i++;//ligne suivante
		if (j == 0)//si la ligne est vide
			ft_putstr_fd("Error\n", 2);
	}
	return (0);
}

int	check_maps(char **two_d)
{
	int	i;
	int	j;
	int	E_found = 0;
	int	C_found = 0;
	int	P_found = 0;

	i = 0;
	while (two_d[i])
	{
		j = 0;
		while (two_d[i][j])
		{
			if (two_d[i][j] == 'E')
				E_found++;
			else if (two_d[i][j] == 'P')
				P_found++;
			else if (two_d[i][j] == 'C')
				C_found++;
			j++;
		}
		i++;
	}
	if (E_found != 1 || C_found == 0 || P_found != 1)
		ft_putstr_fd("Error\n", 2);
	return (0);
}

void	check_valid_char(char **two_d)
{
	int		i;
	int		j;
	char	this_char;

	i = 0;
	while (two_d[i] != NULL)//htal la fin dial tableau
	{
		j = 0;
		while (two_d[i][j] != '\0')//parcourir les aracteres de chaque ligne
		{
			this_char = two_d[i][j];
			if (!(this_char == '0' || this_char == '1' || this_char == 'E' || this_char == 'C' || this_char == 'P'))
				ft_putstr_fd("Error\n", 2);
			j++;//lcaractere suivant dans la meme ligne
		}
		i++;//ligne suivante
	}
}
