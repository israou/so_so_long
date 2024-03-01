/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:49:55 by ichaabi           #+#    #+#             */
/*   Updated: 2024/03/01 04:32:23 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
	char	**two_d;
	t_mlx	map;


	two_d = parse_maps(ac, av);

	map.map = two_d;
	print_img(two_d, map);

	return (0);
}
