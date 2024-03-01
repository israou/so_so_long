/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaabi <ichaabi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:49:27 by ichaabi           #+#    #+#             */
/*   Updated: 2024/02/29 23:55:01 by ichaabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_maps(int ac, char **av)
{
	int		fd;
	char	**two_d;
	t_position	*r;
	t_mlx mlx;


	r = NULL;
	if (ac != 2)
		ft_putstr_fd("Error\n", 2);
	check_extension(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error\n", 2);
	two_d = read_maps(fd, av[1]);
	if (!two_d)
		ft_putstr_fd("Error\n", 2);

	check_empty(two_d);
	check_maps(two_d);
	check_valid_char(two_d);
	check_walls_top_down(two_d);
	check_walls_left_right(two_d);
	valid_P_C_E(two_d);
	check_long_of_map(two_d);
	the_valid_path(two_d, r);
	mlx.map = two_d;
	puts("QRTYU");

	initialize(&mlx);
	return (two_d);
}
